# Projeto Alerta Luminoso e Sonoro com BlackBoard RoboCore

# feito por Rafael e Vinicius

Este projeto utiliza uma placa **BlackBoard da RoboCore** para criar um sistema de sinalização que alterna luzes LED (azul e vermelha) e gera uma variação de frequência sonora utilizando um buzzer piezoelétrico. É ideal para estudos de lógica de programação em microcontroladores, controle de portas digitais/analógicas e manipulação de atuadores.

---

## Componentes Utilizados

* 1x Placa **BlackBoard RoboCore**
* 1x LED Vermelho
* 1x LED Azul
* 1x Buzzer Piezoelétrico (ou alto-falante compatível)
* Resistores adequados para os LEDs (ex: 220Ω ou 330Ω)
* Jumpers / Cabos de conexão
* Protoboard

---

## Esquema de Conexão (Pinout)

| Componente | Pino na BlackBoard | Tipo de Pino |
| :--- | :--- | :--- |
| **LED Azul** | Pino 2 | Digital (Saída) |
| **LED Vermelho** | Pino 4 | Digital (Saída) |
| **Buzzer Piezoelétrico** | Pino A0 | Analógico / Digital (Saída) |

---

## Como o Código Funciona

O código está dividido em duas partes principais:

1. **`setup()`**: 
   * Configura os pinos dos LEDs (`PORTA_LED_AZUL` e `PORTA_LED_VERMELHO`) e do buzzer (`PORTA_PIEZO`) como saídas (`OUTPUT`).

2. **`loop()`**:
   * **Fase 1**: Acende o LED vermelho, apaga o azul e dispara uma sirene/som com frequências subindo progressivamente de **500Hz até 1800Hz**.
   * **Fase 2**: Alterna o estado, acendendo o LED azul, apagando o vermelho e fazendo o som descer progressivamente de **1800Hz até 500Hz**.
   * O ciclo se repete de forma contínua.

---

## Como Executar o Projeto

1. Conecte a sua **BlackBoard RoboCore** ao computador utilizando um cabo USB compatível.
2. Abra a **Arduino IDE**.
3. Monte o circuito na protoboard seguindo a tabela de conexões acima.
4. Copie o código fonte deste repositório e cole na Arduino IDE.
5. Selecione a placa correta em **Ferramentas > Placa** (como a BlackBoard é compatível com o Arduino Uno, selecione **Arduino Uno**) e escolha a porta COM correspondente em **Ferramentas > Porta**.
6. Clique no botão **Carregar** (seta para a direita) para enviar o código para a placa.
