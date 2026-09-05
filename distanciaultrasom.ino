const int PinTrigger = 2;
const int PinEcho = 3;

const float VelocidadeSom_mporus = 0.000340;

void setup() {
  pinMode(PinTrigger, OUTPUT);
  digitalWrite(PinTrigger, LOW);
  pinMode(PinEcho, INPUT);

  Serial.begin(9600);
  delay(100);
}

void loop() {
  // Envia o pulso para disparar o sensor.
  DisparaPulsoUltrassonico();

  // Mede, em microssegundos, a duracao do sinal recebido.
  unsigned long tempoEcho = pulseIn(PinEcho, HIGH);
  float distanciaMetros = CalculaDistancia(tempoEcho);
  float distanciaCentimetros = distanciaMetros * 100.0;

  Serial.print("Distancia em metros: ");
  Serial.println(distanciaMetros, 2);
  Serial.print("Distancia em centimetros: ");
  Serial.println(distanciaCentimetros, 2);
  Serial.println();

  delay(2000);
}

void DisparaPulsoUltrassonico() {
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
}

float CalculaDistancia(unsigned long tempoUs) {
  return (tempoUs * VelocidadeSom_mporus) / 2.0;
}
