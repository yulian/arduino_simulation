void setup()
{
  // PWM 지원하는 디지털 9번, 10번 핀을 출력모드로 설정
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  // 스위치의 입력을 받기위해 디지털 8번핀을 입력모드로 설정
  pinMode(8, INPUT);
}

void loop()
{
  // 가변저항의 입력 값 범위를 map() 함수로 변환
  int inputValue = analogRead(A0);
  int convertedValue = map(inputValue, 0, 1023, 0, 255);
  
  // 스위치의 입력 값에 따라 DC모터의 방향을 제어
  int inputSwitch = digitalRead(8);
  if (inputSwitch == LOW) {
    analogWrite(9, convertedValue);
    analogWrite(10, 0);
  }
  else {
    analogWrite(9, 0);
    analogWrite(10, convertedValue);
  }
}


