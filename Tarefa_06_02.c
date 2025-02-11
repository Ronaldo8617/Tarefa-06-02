#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // Pino GPIO 22 para controle do servo
#define PWM_FREQ 50   // Frequência do PWM em Hz
#define WRAP_VALUE 20000 // Período de 20ms (50Hz), considerando clock ajustado

// Valores de duty cycle para os ângulos do servo
#define PULSE_0 500      // 0 graus - 500us
#define PULSE_90 1470    // 90 graus - 1470us
#define PULSE_180 2400   // 180 graus - 2400us

// Configuração do PWM
void pwm_setup() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);  // Define GPIO como saída PWM
    uint slice = pwm_gpio_to_slice_num(SERVO_PIN); // Obtém o slice do PWM
    
    pwm_set_wrap(slice, WRAP_VALUE); // Define o valor de wrap para 20ms
    pwm_set_clkdiv(slice, 125.0f);   // Ajusta o divisor para obter 50Hz
    pwm_set_enabled(slice, true);    // Habilita o PWM
}

// Define a posição do servo
void set_servo_position(uint16_t pulse_width) {
    pwm_set_gpio_level(SERVO_PIN, pulse_width);
}

int main() {
    stdio_init_all();
    pwm_setup();
    
    // Movimentação inicial
    printf("Movendo para 180 graus\n");
    set_servo_position(PULSE_180);
    sleep_ms(5000);

    printf("Movendo para 90 graus\n");
    set_servo_position(PULSE_90);
    sleep_ms(5000);

    printf("Movendo para 0 graus\n");
    set_servo_position(PULSE_0);
    sleep_ms(5000);

    // Movimentação contínua e suave entre 0 e 180 graus
    printf("Movimentação suave contínua\n");
    while (true) {
        // Movimentação de 0 a 180 graus
        for (uint16_t pos = PULSE_0; pos <= PULSE_180; pos += 5) {
            set_servo_position(pos);
            sleep_ms(10); // Atraso de 10ms para movimentação suave
        }

        // Movimentação de 180 a 0 graus
        for (uint16_t pos = PULSE_180; pos >= PULSE_0; pos -= 5) {
            set_servo_position(pos);
            sleep_ms(10); // Atraso de 10ms para movimentação suave
        }
    }
}