# Tarefa 06/02 - Controle de Servo Motor

Este projeto utiliza o Raspberry Pi Pico para controlar um servomotor através do PWM. O código implementa a movimentação do braço do servo para posições específicas e uma rotina contínua de movimentação suave entre 0 e 180 graus.

## Requisitos Atendidos

### 1) Configuração do PWM na GPIO 22
✅ Frequência definida em **50Hz** (período de 20ms).

### 2) Movimentação Inicial do Servo
✅ **Posição 180 graus** – Pulso de **2.400µs** (0,12% duty cycle), aguardando **5 segundos**.

✅ **Posição 90 graus** – Pulso de **1.470µs** (0,0735% duty cycle), aguardando **5 segundos**.

✅ **Posição 0 graus** – Pulso de **500µs** (0,025% duty cycle), aguardando **5 segundos**.

### 3) Movimentação Suave Contínua
✅ O código implementa um laço que movimenta suavemente o servo **entre 0 e 180 graus**.

✅ **Incremento de ±5µs** a cada **10ms**, garantindo uma movimentação contínua e fluida.
### 4) Teste com LED
✅ Ao substituir o servo-motor por um led, aconteceu de que o led alternou a sua intensidade de acordo com o duty cycle
O Duty cycle controla a intensidade luminosa de forma proporcional a sua magnitude

## Como Usar
1. **Clonar o repositorio do Github**
2. **Compilar e carregar o código** no Raspberry Pi Pico.
3. **Executar o programa** para visualizar a movimentação inicial e a movimentação contínua do servo.

## Bibliotecas Utilizadas
- `stdio.h` – Para entrada e saída de dados.
- `pico/stdlib.h` – Para uso das funções básicas do Raspberry Pi Pico.
- `hardware/pwm.h` – Para controle do PWM no Raspberry Pi Pico.

## Video Demonstrativo
- Link para o video: https://www.youtube.com/watch?v=7qEw6y60H_0



