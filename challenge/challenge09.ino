void setup()
{
  pinMode(10, OUTPUT);  // 10번 핀을 트리거로 사용
  pinMode(9, INPUT);    // 9번 핀을 에코로 사용
  Serial.begin(9600);
}

void loop()
{
  // 초음파 신호 송신
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);
  
  // 초음파 신호 수신
  pinMode(9, INPUT);
  double duration = pulseIn(9, HIGH);
  double cm = duration * 340 / 10000 / 2;
  
  // 측정거리를 출력
  Serial.println(cm);
}

