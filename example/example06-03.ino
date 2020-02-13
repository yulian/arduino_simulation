void setup()
{
  Serial.begin(9600);             // 시리얼 통신을 위한 보드레이트 설정
  
  pinMode(8, OUTPUT);             // 8번 디지털 핀을 출력모드로 설정
  pinMode(7, INPUT);              // 7번 디지털 핀을 입력모드로 설정
}

void loop()
{
  int readValue = digitalRead(7); // 입력핀의 값을 읽어 변수에 저장
  Serial.println(readValue);      // 변수의 값을 시리얼 모니터에 출력
  
  if(readValue == HIGH) {         // 입력 값에 따라 LED 출력값 제어
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }
}

