#include <iostream>
#include <ctime>
#include <thread>

#include "RFF.h"
#include "SGP4.h"


struct TimerEvent{ std::clock_t emissionTime; };
struct RequirePropagate{ Tle TwoLineElements; DateTime EndTime; };

void propagator(RequirePropagate const& propagation) {
    std::cout << "Initializing propagator" << std::endl;
    SGP4 sgp4(propagation.TwoLineElements);
    auto start = std::clock();

    std::cout << "Starting propagation" << std::endl;
    auto calculated_pos = sgp4.FindPosition(propagation.EndTime);
    std::cout << calculated_pos.ToGeodetic();

    auto duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Propagation time : " << duration << std::endl;


}

void timerHandler(TimerEvent const& evt) {
    auto tle = Tle{"ISS (ZARYA)", "1 25544U 98067A   20237.19927083  .00000402  00000-0  15362-4 0  9990", "2 25544  51.6471  11.8824 0001577  59.0436 306.4808 15.49181383242568"};
    RFF::emit(RequirePropagate{tle, tle.Epoch().AddHours(6)});
}

void timer_15sec(void*) {
    auto start = std::chrono::high_resolution_clock::now();
    while(1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>{now-start};
        std::cout << duration.count() << std::endl;
        if(duration.count() >= 15000) {
            RFF::emit(TimerEvent{std::clock()});
            start = std::chrono::high_resolution_clock::now(); // Reset the clock
        }
    }
}

RFF::Task<1, 2048> timerTask{timer_15sec, "TimerTask"};

RFF::EventHandler<TimerEvent, 2> PropagatorTimer{timerHandler};
RFF::EventHandler<RequirePropagate> Propagator{propagator};
RFF::Module PropagationModule{PropagatorTimer, Propagator};

RFF::Setup setup{PropagationModule};

void rff_main() {}