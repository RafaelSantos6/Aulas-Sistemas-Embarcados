# Projeto Sensor de Ré com BlackBoard RoboCore

# feito por Rafael e Vinicius

Este projeto utiliza uma placa **BlackBoard da RoboCore** integrada a um **sensor ultrassônico (HC-SR04)**, um **LED RGB** e um **buzzer piezoelétrico** para simular o funcionamento de um sensor de estacionamento automotivo (sensor de ré). O sistema afere a distância em relação a obstáculos em tempo real e fornece alertas visuais e sonoros proporcionais à proximidade. É ideal para o aprendizado de medição de tempo de pulso, cálculo de distância, controle de LED RGB e modulação de alertas sonoros em microcontroladores.

---

## Componentes Utilizados

* 1x Placa **BlackBoard RoboCore** (compatível com Arduino Uno)
* 1x Sensor Ultrassônico **HC-SR04**
* 1x LED RGB
* 1x Buzzer Piezoelétrico
* 3x Resistores adequados para os canais do LED RGB (ex: 220Ω ou 330Ω)
* Jumpers / Cabos de conexão
* Protoboard

---

## Esquema de Conexão (Pinout)

| Componente | Pino na BlackBoard | Tipo de Pino |
| :--- | :--- | :--- |
| **Sensor HC-SR04 (Trig)** | Pino 3 | Digital (Saída) |
| **Sensor HC-SR04 (Echo)** | Pino 2 | Digital (Entrada) |
| **Buzzer Piezoelétrico** | Pino 9 | Digital (Saída) |
| **LED RGB (Vermelho)** | Pino 12 | Digital (Saída) |
| **LED RGB (Verde)** | Pino 10 | Digital (Saída) |
| **LED RGB (Azul)** | Pino 11 | Digital (Saída) |
| **Sensor HC-SR04 (VCC)** | 5V | Alimentação |
| **Sensor HC-SR04 (GND)** | GND | Terra |
| **LED RGB / Buzzer (GND)** | GND | Terra |

---

## Como o Código Funciona

O código está dividido em duas partes principais:

1. **`setup()`**: 
   * Configura o pino de disparo (`trigPin`) como saída (`OUTPUT`) e o pino de eco (`echoPin`) como entrada (`INPUT`).
   * Configura os pinos do buzzer (`buzzerPin`) e as cores do LED RGB (`ledVermelho`, `ledVerde`, `ledAzul`) como saídas (`OUTPUT`).
   * Inicializa a comunicação serial em 9600 bps (`Serial.begin(9600)`) para monitoramento dos dados de distância no computador.

2. **`loop()`**:
   * **Emissão e Leitura Ultrassônica**: Envia um pulso de 10 microssegundos através do `trigPin` e mede a duração do pulso de retorno através da função `pulseIn(echoPin, HIGH)`.
   * **Cálculo da Distância**: Converte o tempo de viagem da onda sonora para centímetros usando a relação `duracao * 0.034 / 2` e exibe o valor no Monitor Serial.
   * **Lógica de Alerta por Faixa de Distância**:
     * **Distância Segura (> 40 cm)**: Acende o LED na cor **verde** e mantém o buzzer desligado (`noTone`).
     * **Alerta Moderado (entre 15 cm e 40 cm)**: Acende os canais verde e vermelho simultaneamente para formar a cor **amarela** e dispara bips sonoros intermitentes em 800Hz (200ms ligado e 300ms desligado).
     * **Perigo / Proximidade Crítica (≤ 15 cm)**: Acende o LED na cor **vermelha** e ativa o buzzer com **som contínuo** em 800Hz.
     * **Leitura Inválida ou Fora de Alcance (≤ 0 cm)**: Apaga todos os LEDs e silencia o buzzer.

---

## Como Executar o Projeto

1. Conecte a sua **BlackBoard RoboCore** ao computador utilizando um cabo USB compatível.
2. Abra a **Arduino IDE**.
3. Monte o circuito na protoboard seguindo a tabela de conexões acima.
4. Abra o código fonte [`sensor.ino`](file:///home/rafael-ricetti/%C3%81rea%20de%20trabalho/Aulas-Sistemas-Embarcados/CodigosArduino/sensor.ino) na Arduino IDE.
5. Selecione a placa correta em **Ferramentas > Placa** (como a BlackBoard é compatível com o Arduino Uno, selecione **Arduino Uno**) e escolha a porta COM correspondente em **Ferramentas > Porta**.
6. Clique no botão **Carregar** (seta para a direita) para enviar o código para a placa.
7. Abra o **Monitor Serial** (Ctrl + Shift + M) com a velocidade configurada para **9600 baud** para acompanhar em tempo real as distâncias medidas.

