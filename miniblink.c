#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/*
 * MiniBlink - STM32F103C8T6 (Blue Pill)
 * LED: PC13
 */

void delay(volatile uint32_t time)
{
    while (time--) {
        __asm__("nop");
    }
}

int main(void)
{
    /* Enable clock for GPIOC */
    rcc_periph_clock_enable(RCC_GPIOC);

    /* Configure PC13 as output push-pull */
    gpio_set_mode(GPIOC,
                  GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_PUSHPULL,
                  GPIO13);

    while (1) {
        gpio_toggle(GPIOC, GPIO13);
        delay(800000);
    }
}
