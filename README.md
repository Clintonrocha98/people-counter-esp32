# Contador de pessoas com ESP32 e sensores ultrassônicos

[Link do projeto no WOKWI](https://wokwi.com/projects/407437023017695233)

## Funcionalidade

O projeto funciona da seguinte maneira:

1. Sensores Ultrassônicos: Dois sensores ultrassônicos são utilizados para detectar a passagem de pessoas. Eles são posicionados em locais estratégicos para detectar movimento na entrada e saída de um ambiente.

2. Medição da Distância: Cada sensor envia um pulso ultrassônico e mede o tempo que leva para o pulso refletido retornar. Com base nesse tempo, o código calcula a distância do objeto mais próximo (neste caso, uma pessoa).

3. Contagem de Pessoas:

- Quando uma pessoa entra no ambiente (determinada pela ordem de ativação dos sensores), o contador de pessoas é incrementado, o LED verde pisca, e uma requisição HTTP POST é enviada para o endpoint configurado.
- Quando uma pessoa sai (determinada pela ordem inversa de ativação dos sensores), o contador é decrementado, o LED vermelho pisca, e uma requisição HTTP POST é enviada para o endpoint configurado.
In

4. Idicação Visual:

- Um LED verde pisca para indicar uma entrada.
- Um LED vermelho pisca para indicar uma saída.

5. Notificação HTTP:

- Quando o número de pessoas muda, uma requisição HTTP POST é feita para um endpoint especificado (variavel URL), enviando o número atualizado de pessoas presentes no ambiente.

## Configuração WiFi

Antes de carregar o código no ESP32, certifique-se de atualizar as seguintes informações com o nome e senha da sua rede WiFi:

```cpp
const char* ssid = "NOME_DA_REDE";
const char* password = "SENHA_DA_REDE";
```

## Configuração do endpoint

Atualize a URL do endpoint HTTP no código conforme necessário:

```cpp
const char* URL = "http://URL-FODA/notifica";
```

Certifique-se de que o servidor esteja configurado para receber as requisições HTTP POST enviadas pelo ESP32.

## Componentes utilizados

- ESP32: Microcontrolador para controlar os sensores, LEDs, e fazer requisições HTTP.
-  2 Sensores Ultrassônicos (HC-SR04 ou similar): Para detectar a presença de pessoas.
- LEDs (Vermelho e Verde): Para indicar visualmente entradas e saídas.
- Protoboard e Jumpers: Para conexão dos componentes.

## Esquema de conexão

- TRIG_one do sensor ultrassônico 1 conectado ao pino GPIO 26 do ESP32.
- ECHO_one do sensor ultrassônico 1 conectado ao pino GPIO 27 do ESP32.
- TRIG_two do sensor ultrassônico 2 conectado ao pino GPIO 17 do ESP32.
- ECHO_two do sensor ultrassônico 2 conectado ao pino GPIO 18 do ESP32.
- LED Verde conectado ao pino GPIO 12 do ESP32.
- LED Vermelho conectado ao pino GPIO 23 do ESP32.


