
const int IN1 = 6;
const int IN2 = 5;
const int IN3 = 9;
const int IN4 = 10;
const int ENA = 3;
const int ENB = 11;
const int pinEcho = 12;
const int pinTrig = 13;
const int velocidadeA = 210; 
const int velocidadeB = 195; 

const int tempoGiroDesvio = 460;          
const int tempoPassarCaixa = 1200;        
const int tempoGiroRealinhamento = 950;   

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinTrig, LOW);
}

void loop() {
  if (detectouObjeto()) {
    
    parar();
    delay(200);

    girarDireitaForte();
    delay(tempoGiroDesvio);
    parar();
    delay(200);

    andarFrente();
    delay(tempoPassarCaixa);

    parar();
    delay(300);

    girarEsquerdaForte();
    delay(tempoGiroRealinhamento);

    parar();
    delay(800); 

    andarFrente();
    delay(1500);
  } else {
    
    andarFrente();
  }

  delay(30); 
}

bool detectouObjeto() {
  long d1 = lerDistancia();
  if (d1 >= 4 && d1 <= 22) {
    delay(25);
    long d2 = lerDistancia();
    if (d2 >= 4 && d2 <= 22) {
      return true;
    }
  }
  return false;
}

long lerDistancia() {
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  long duracao = pulseIn(pinEcho, HIGH, 25000); 
  if (duracao == 0) {
    return 999;
  }
  
  long cm = duracao / 58;
  return cm;
}

void andarFrente() {
  analogWrite(ENA, velocidadeA);
  analogWrite(ENB, velocidadeB);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void girarDireitaForte() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void girarEsquerdaForte() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
