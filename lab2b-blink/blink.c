/**
 * Nikola Obradovic
 */

#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "pico/stdio.h"
#include "hardware/gpio.h"


#define LED_PIN 29

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    
    int inputchar;

    printf("press 1/0 to toggle\n");
    
    while (1) {

            inputchar = getchar_timeout_us(10000);
            if (inputchar != PICO_ERROR_TIMEOUT) {
                putchar((char)inputchar);
                if ((char)inputchar == '1') {
                    gpio_put(LED_PIN, 1);
                }
                if ((char)inputchar == '0') {
                    gpio_put(LED_PIN, 0);
                }
            }

    }
}