

#define FFS_CROSS

#include <iostream>
#include "FFS.h"
#include <csignal>
#include <cstdlib>
// #include <chrono>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

struct BlinkEvent { int eventNo; };

void blinker(BlinkEvent const& evt) {
    gpio_toggle(GPIOG, GPIO13);
    std::cout << "t";
}



void timer(void*) {
    while(1) {
        for (int i = 0; i < 1000000; i++) {	/* Wait a bit. */
            __asm__("nop");
        }
        
        FFS::emit(BlinkEvent{});
    }
    
}


FFS::EventHandler<BlinkEvent, 1, 16, 2048> h1{blinker, "blinker"};
FFS::Module m1{h1};

FFS::Setup setup{std::make_tuple(FFS::Mode{"abc"}), m1};

FFS::Task<1, 512> t1{timer, "timer"};

int __io_putchar(int ch) {
    uart_send(UART1, ch);
    return 0;
}

void ffs_main() {
    rcc_periph_clock_enable(RCC_GPIOG); // Enable clock GPIOC

    gpio_mode_setup(GPIOG, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13); // Configure GPIO13

    // Enable the UART clock
    periph_clock_enable(RCC_UART1);
    // We need a brief delay before we can access UART config registers
    __asm__("nop"); __asm__("nop"); __asm__("nop");
    // Disable the UART while we mess with its settings
    uart_disable(UART1);
    // Configure the UART clock source as precision internal oscillator
    uart_clock_from_piosc();
    // Set communication parameters
    uart_set_baudrate(UART1, 115200);
    uart_set_databits(UART1, 8);
    uart_set_parity(UART1, UART_PARITY_NONE);
    uart_set_stopbits(UART1, 1);
    // Enable RTC and CTS lines
    uart_set_flow_control(UART1, UART_FLOWCTL_HARD_RTS_CTS);
    // Now that we're done messing with the settings, enable the UART
    uart_enable(UART1);

}

