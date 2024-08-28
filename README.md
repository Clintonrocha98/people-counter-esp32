# Contador de Pessoas com ESP32 e Sensores Ultrassônicos

[Link do projeto no WOKWI](https://wokwi.com/projects/407437023017695233)

Este projeto utiliza um microcontrolador ESP32 junto com dois sensores ultrassônicos para monitorar e contar o número de pessoas que entram e saem de um ambiente. Quando uma pessoa entra, um LED verde pisca; quando uma pessoa sai, um LED vermelho pisca. O objetivo do projeto é fornecer uma maneira eficiente de contar o fluxo de pessoas em um determinado local, como uma sala ou um corredor.

## Funcionalidade

O projeto funciona da seguinte maneira:

1. **Sensores Ultrassônicos**: Dois sensores ultrassônicos são utilizados para detectar a passagem de pessoas. Eles são posicionados em locais estratégicos para detectar movimento na entrada e saída de um ambiente.

2. **Medição da Distância**: Cada sensor envia um pulso ultrassônico e mede o tempo que leva para o pulso refletido retornar. Com base nesse tempo, o código calcula a distância do objeto mais próximo (neste caso, uma pessoa).

3. **Contagem de Pessoas**:
   - Quando uma pessoa entra no ambiente (determinada pela ordem de ativação dos sensores), o contador de pessoas é incrementado e o LED verde pisca.
   - Quando uma pessoa sai (determinada pela ordem inversa de ativação dos sensores), o contador é decrementado e o LED vermelho pisca.

4. **Indicação Visual**:
   - Um LED verde pisca para indicar uma entrada.
   - Um LED vermelho pisca para indicar uma saída.

## Componentes Utilizados

- **ESP32**: Microcontrolador para controlar os sensores e LEDs.
- **2 Sensores Ultrassônicos (HC-SR04 ou similar)**: Para detectar a presença de pessoas.
- **LEDs (Vermelho e Verde)**: Para indicar visualmente entradas e saídas.
- **Protoboard e Jumpers**: Para conexão dos componentes.

## Esquema de Conexão

- **TRIG_one** do sensor ultrassônico 1 conectado ao pino GPIO 26 do ESP32.
- **ECHO_one** do sensor ultrassônico 1 conectado ao pino GPIO 27 do ESP32.
- **TRIG_two** do sensor ultrassônico 2 conectado ao pino GPIO 17 do ESP32.
- **ECHO_two** do sensor ultrassônico 2 conectado ao pino GPIO 18 do ESP32.
- **LED Verde** conectado ao pino GPIO 12 do ESP32.
- **LED Vermelho** conectado ao pino GPIO 23 do ESP32.


