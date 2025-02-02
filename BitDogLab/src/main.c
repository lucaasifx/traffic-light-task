#include <stdio.h>


#include "pico/stdlib.h"
#include "hardware/timer.h"


// ************************ LIBS ***************************
// biblioteca para manipulação de leds
#include "lib/led.h"
// biblioteca para manipulação de botões
#include "lib/button.h"
// biblioteca para manipulação de eventos de interrupção
#include "lib/interrupt.h"

// ************************ MACROS ***************************

volatile uint8_t cycle = 1;

// Função de repeating
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (cycle) {
        // sinal vermelho
        case 1:
            turn_led_off(LED_GREEN);
            turn_led_on(LED_RED);
            puts("\n");
            printf("Sinal Vermelho\n");
            cycle++;
            break;
        // sinal amarelo
        case 2:
            turn_led_on(LED_RED);
            turn_led_on(LED_GREEN);         
            printf("Sinal Amarelo\n");
            cycle++;
            break;
        // sinal verde
        case 3:
            turn_led_off(LED_RED);         
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
    // Inicializa os 2 leds
        // Na BitDogLab, o amarelo é formado pelos
        //      leds vermelho e verde ligados simultaneamente
    init_led(LED_RED);   
    init_led(LED_GREEN);
    
    // habilita a entrada no modo BOOTSELL ao pressionar o botao
        // do Joystick da BitDogLab
    init_button_with_interrupt(JOYSTICK_BUTTON, GPIO_IRQ_EDGE_FALL, true);

    // leds começam desligados
    turn_led_off(LED_RED);
    turn_led_off(LED_GREEN);


    // nosso temporizador de repetição
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while(true) {
        printf("1 segundo se passou\n");
        sleep_ms(1000);
    }
    return 0;
}
