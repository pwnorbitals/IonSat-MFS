#include <iostream>
#include "RFF.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

int __io_putchar(int ch) {
    usart_send(USART1, ch);
    return 0;
}

void blinker(void*) {
    while(1) {
        gpio_toggle(GPIOG, GPIO13 | GPIO14);	
        std::cout << "t";
        RFF::delay(1 * configTICK_RATE_HZ); 
    }
}
 // TODO : switch to timers
RFF::Task<9, 10000> blinkerTask{blinker, "BlinkerTask"};

RFF::Setup setup{};

void rff_main() {
    rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);


    rcc_periph_clock_enable(RCC_GPIOG);
    rcc_periph_clock_enable(RCC_USART1);

    gpio_mode_setup(GPIOG, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13 | GPIO14);
    gpio_toggle(GPIOG, GPIO13 | GPIO14);

    
    
    /* Setup USART1 parameters. */
	usart_set_baudrate(USART1, 115200);
	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_mode(USART1, USART_MODE_TX);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);

	/* Finally enable the USART. */
	usart_enable(USART1);
}