void setup()
{
  Serial.begin(9600);             // 시리얼 통신 초기화
}

void loop()
{
  int readValue = analogRead(A0); // 아날로그 신호를 측정
  Serial.println(readValue);      // 아날로그 값 출력
}

