int leitura, s, p, p2,p3,p4,p5;
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  leitura = analogRead(3);
  if (leitura < 200){
    analogWrite(6, 50);
  }
  if ((leitura > 200) && (leitura <400)){
    analogWrite(6, 100);
    analogWrite(5, 50);
  }
  if ((leitura > 400) && (leitura < 600)){
    analogWrite(6, 150);
    analogWrite(5, 100);
    analogWrite(4, 50);
  }
  if ((leitura > 600) && (leitura < 800)){
    analogWrite(6, 200);
    analogWrite(5, 150);
    analogWrite(4, 100);
    analogWrite(3, 50);
  }
  if ((leitura > 800) && (leitura < 1000)){
    analogWrite(6, 255);
    analogWrite(5, 200);
    analogWrite(4, 150);
    analogWrite(3, 100);
    analogWrite(2, 50);
  }
}