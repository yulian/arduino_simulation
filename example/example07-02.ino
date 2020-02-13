void setup()
{
  Serial.begin(9600);             // 시리얼 통신 초기화
  
  pinMode(13, OUTPUT);            // 디지털 13번 핀을 출력모드로 변경
}

void loop()
{
  int readValue = analogRead(A0); // 아날로그 신호를 측정
  Serial.println(readValue);      // 아날로그 값 출력
  
  if(readValue < 500)             // 아날로그 값에 따라 LED 제어
    digitalWrite(13, LOW);
  else
    digitalWrite(13, HIGH);
}

