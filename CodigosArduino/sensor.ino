// Definição dos pinos com base no seu circuito[cite: 2]
const int trigPin = 3;
const int echoPin = 2;
const int buzzerPin = 9;
 
// Pinos do LED RGB[cite: 2]
const int ledVermelho = 12;
const int ledVerde = 10;
const int ledAzul = 11;
 
void setup() {
  // Configuração dos pinos do sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Configuração do buzzer e das cores do LED RGB
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  // Inicializa a comunicação serial para testes
  Serial.begin(9600);
}
 
void loop() {
  // Envia o pulso de ultrassom
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Lê o tempo de retorno do eco
  long duracao = pulseIn(echoPin, HIGH);
  // Converte o tempo para centímetros
  int distancia = duracao * 0.034 / 2;
  // Exibe a distância no Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  // Lógica de proximidade (Sensor de Ré)
  if (distancia > 40) {
    // >> Distância Segura: LED VERDE e SEM SOM <<
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, LOW);
    noTone(buzzerPin);
  } 
  else if (distancia <= 40 && distancia > 15) {
    // >> Alerta Moderado: LED AMARELO e SOM PAUSADO (bip intermitente) <<
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, HIGH); // Mistura para formar amarelo
    digitalWrite(ledAzul, LOW);
    tone(buzzerPin, 800); // Liga o som
    delay(200);            // Tempo tocando
    noTone(buzzerPin);     // Desliga o som
    delay(300);            // Tempo pausado
  } 
  else if (distancia <= 15 && distancia > 0) {
    // >> Perigo / Muito Perto: LED VERMELHO e SOM CONTÍNUO <<
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAzul, LOW);
    tone(buzzerPin, 800); // Som contínuo ativado (sem comandos de pausa)
  } 
  else {
    // Caso ocorra alguma leitura inválida ou fora do alcance
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, LOW);
    noTone(buzzerPin);
  }
}