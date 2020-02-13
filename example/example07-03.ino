void setup()
{
  Serial.begin(9600);             // 시리얼 통신 초기화
  
  pinMode(13, OUTPUT);            // 디지털 13번 핀을 출력모드로 변경
}

void loop()
{
  int readValue = analogRead(A0); // 아날로그 신호를 측정
  Serial.println(readValue);      // 아날로그 값 출력
  
  digitalWrite(13, LOW);
  delay(readValue);               // 지연시간을 변수로 제어
  digitalWrite(13, HIGH);
  delay(readValue);               // 지연시간을 변수로 제어
}

