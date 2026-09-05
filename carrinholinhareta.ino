const int IN1 = 6;
const int IN2 = 5;
const int IN3 = 9;
const int IN4 = 10;


const int ENA = 3;
const int ENB = 11;


const int ajusteVelocidadeA = 210; 
const int ajusteVelocidadeB = 195; 

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  
  analogWrite(ENA, ajusteVelocidadeA);
  analogWrite(ENB, ajusteVelocidadeB);

  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
