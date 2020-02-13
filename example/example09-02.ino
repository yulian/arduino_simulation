void setup()
{
  pinMode(7, OUTPUT);	// 빨간색 LED
  pinMode(6, OUTPUT);	// 노란색 LED
  pinMode(5, OUTPUT);	// 초록색 LED
}

void loop()
{
  // 초음파 신호 송신
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(5);
  digitalWrite(9, LOW);
  
  // 초음파 신호 수신
  pinMode(9, INPUT);
  double duration = pulseIn(9, HIGH);
  double cm = duration * 340 / 10000 / 2;
  
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  
  // 물체의 측정거리에 따라 LED를 제어
  if (cm < 20) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  else if(cm < 60) {
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  
  delay(100);
}

