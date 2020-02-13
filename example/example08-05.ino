void setup()
{
  // PWM 지원하는 디지털 9번 핀을 출력모드로 설정
  pinMode(9, OUTPUT);
}

void loop()
{
  // 가변저항의 입력 값 범위를 map() 함수로 변환
  int inputValue = analogRead(A0);
  int convertedValue = map(inputValue, 0, 1023, 0, 255);
  
  // 가변저항의 값에 따라 모터의 속도를 조절
  analogWrite(9, convertedValue);
  
  delay(100);
}


