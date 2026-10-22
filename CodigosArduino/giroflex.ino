const int PORTA_LED_AZUL = 2;
const int PORTA_LED_VERMELHO = 4;
const int PORTA_PIEZO = A0;
 
void setup()
{
  pinMode(PORTA_LED_AZUL, OUTPUT);
  pinMode(PORTA_LED_VERMELHO, OUTPUT);
  pinMode(PORTA_PIEZO, OUTPUT);
}
 
void loop()
{
  digitalWrite(PORTA_LED_VERMELHO, HIGH);
  digitalWrite(PORTA_LED_AZUL, LOW);

  digitalWrite(PORTA_LED_VERMELHO, HIGH);
  digitalWrite(PORTA_LED_AZUL, LOW);
 
  for (int frequencia = 500; frequencia <= 1800; frequencia += 20) {
    tone(PORTA_PIEZO, frequencia);
    delay(10);
  }
 
  digitalWrite(PORTA_LED_VERMELHO, LOW);
  digitalWrite(PORTA_LED_AZUL, HIGH);
 
  for (int frequencia = 1800; frequencia >= 500; frequencia -= 20) {
    tone(PORTA_PIEZO, frequencia);
    delay(10);
  }
 
  noTone(PORTA_PIEZO); 
}