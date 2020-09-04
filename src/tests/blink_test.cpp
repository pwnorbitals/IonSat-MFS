#include <iostream>
#include "RFF.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

void blinker(void*) {
    while(1) {
        gpio_toggle(GPIOG, GPIO13 | GPIO14);	
        RFF::delay(1 * configTICK_RATE_HZ); 
    }
}

RFF::Task<9, 10000> blinkerTask{blinker, "BlinkerTask"};


RFF::Setup setup{};

void rff_main() {
    rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
    rcc_periph_clock_enable(RCC_GPIOG);
    gpio_mode_setup(GPIOG, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13 | GPIO14);
    gpio_toggle(GPIOG, GPIO13 | GPIO14);
}