void setup()
{
  pinMode(13, OUTPUT);      // 아두이노의 13번 핀을 출력모드로 설정
  pinMode(12, OUTPUT);      // 아두이노의 12번 핀을 출력모드로 설정
}

void loop()
{
  digitalWrite(13, HIGH);   // 아두이노의 13번 핀에 HIGH 신호를 전달
  digitalWrite(12, LOW);    // 아두이노의 12번 핀에 LOW 신호를 전달
  delay(1000);              // 1초 동안 지연
  
  digitalWrite(13, LOW);    // 아두이노의 13번 핀에 LOW 신호를 전달
  digitalWrite(12, HIGH);   // 아두이노의 12번 핀에 HIGH 신호를 전달
  delay(1000);              // 1초 동안 지연
}

