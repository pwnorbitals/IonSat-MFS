#include <iostream>
#include <ctime>
#include <thread>

#include "RFF.h"
#include "SGP4.h"


struct TimerEvent{ std::clock_t emissionTime; };
struct RequirePropagate{ };

void propagator(RequirePropagate const& propagation) {
    std::cout << "Initializing propagator" << std::endl;
    auto tle = Tle{"ISS (ZARYA)", "1 25544U 98067A   20237.19927083  .00000402  00000-0  15362-4 0  9990", "2 25544  51.6471  11.8824 0001577  59.0436 306.4808 15.49181383242568"};
    auto end = tle.Epoch().AddHours(6);
    SGP4 sgp4(tle);
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Starting propagation" << std::endl;
    auto calculated_pos = sgp4.FindPosition(end);
    std::cout << calculated_pos.ToGeodetic() << std::endl;

    auto duration = std::chrono::duration<double, std::milli>{std::chrono::high_resolution_clock::now() - start};
    std::cout << "Propagation time : " << duration.count()/1000 << std::endl;


}

void timerHandler(TimerEvent const& evt) {
    
    RFF::emit(RequirePropagate{});
}

void timer_15sec(void*) {
    auto start = std::chrono::high_resolution_clock::now();
    while(1) {
        RFF::Task<1, 2048>::delay(100);
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>{now-start};
        std::cout << duration.count() << std::endl;
        if(duration.count() >= 15000) {
            RFF::emit(TimerEvent{std::clock()});
            start = std::chrono::high_resolution_clock::now(); // Reset the clock
        }
    }
}

RFF::Task<9, 2048> timerTask{timer_15sec, "TimerTask"};

RFF::EventHandler<TimerEvent, 2> PropagatorTimer{timerHandler};
RFF::EventHandler<RequirePropagate> Propagator{propagator};
RFF::Module PropagationModule{PropagatorTimer, Propagator};

RFF::Setup setup{PropagationModule};

void rff_main() {}