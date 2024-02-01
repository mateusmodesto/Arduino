int verde, azul, vermelho, pverde, pvermelho, pazul;
void setup() {
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  pverde = analogRead(A1);
  pvermelho = analogRead(A2);
  pazul = analogRead(A3);
  pverde = map(pverde,0,1023,0,255);
  pvermelho = map(pvermelho,0,1023,0,255);
  pazul = map(pazul,0,1023,0,255);
  analogWrite(8, pverde);
  analogWrite(9, pvermelho);
  analogWrite(10,pazul);
}
