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

volatile uint8_t cycle = 0;

// Função de repeating
bool repeating_timer_callback() {
    
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

    // nosso temporizador de repetição
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while(true) {
        // para evitar que a CPU fique sobrecarregada
        sleep_ms(100);
    }
    return 0;
}