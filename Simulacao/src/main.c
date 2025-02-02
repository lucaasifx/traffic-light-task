#include <stdio.h>


#include "pico/stdlib.h"
#include "hardware/timer.h"


// ************************ LIBS ***************************
// biblioteca para manipulação de leds
#include "lib/led.h"


// ************************ MACROS ***************************

// específico para a simulação
#define LED_YELLOW 1

// responsável por controlar o sinal atual
    // inicialmente vermelho
volatile uint8_t cycle = 1;

// Função de repeating
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (cycle) {
        // sinal vermelho
        case 1:
            turn_led_off(LED_YELLOW);
            turn_led_off(LED_GREEN);
            turn_led_on(LED_RED);
            puts("\n");
            printf("Sinal Vermelho\n");
            cycle++;
            break;
        // sinal amarelo
        case 2:
            turn_led_off(LED_RED);
            turn_led_off(LED_GREEN);         
            turn_led_on(LED_YELLOW);
            printf("Sinal Amarelo\n");
            cycle++;
            break;
        // sinal verde
        case 3:
            turn_led_off(LED_RED);
            turn_led_off(LED_YELLOW);         
            turn_led_on(LED_GREEN);
            printf("Sinal Verde\n");
            cycle = 1;
            break;
        default:
            break;
    }
    return true;
}


int main() {
    stdio_init_all();
    // Inicializa os 3 leds
    init_led(LED_RED);
    init_led(LED_YELLOW);   
    init_led(LED_GREEN);

    // leds começam desligados
    turn_led_off(LED_RED);
    turn_led_off(LED_YELLOW);
    turn_led_off(LED_GREEN);

    // início do ciclo
    turn_led_on(LED_RED);
    printf("Sinal Vermelho\n");
    cycle++;

    // nosso temporizador de repetição
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    while(true) {
        printf("1 segundo se passou\n");
        sleep_ms(1000);
    }
    return 0;
}