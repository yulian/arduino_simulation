void setup()
{
  Serial.begin(9600);
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
  
  // 측정거리를 출력
  Serial.println(cm);
}

