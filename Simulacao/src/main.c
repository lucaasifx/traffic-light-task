#include <stdio.h>


#include "pico/stdlib.h"
#include "hardware/timer.h"


// ************************ LIBS ***************************
// biblioteca para manipulação de leds
#include "lib/led.h"


// ************************ MACROS ***************************

// específico para a simulação
#define LED_YELLOW 1

volatile uint8_t cycle = 0;

// Função de repeating
bool repeating_timer_callback() {
    
}


int main() {
    stdio_init_all();
    // Inicializa os 3 leds
    init_led(LED_RED);
    init_led(LED_YELLOW);   
    init_led(LED_GREEN);

    // nosso temporizador de repetição
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    while(true) {
        // para evitar que a CPU fique sobrecarregada
        sleep_ms(100);
    }
    return 0;
}