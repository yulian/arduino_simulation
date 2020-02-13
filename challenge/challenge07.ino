void setup()
{
  pinMode(13, OUTPUT);                      // 13번 핀을 출력 모드로 설정
  Serial.begin(9600);                       // 시리얼 통신 초기화
}

void loop()
{
  int analogInput = analogRead(A0);         // 온도센서(TMP36) 값 측정
  float voltage = analogInput*5.0/1023.0;   // 전압값 변환
  float temperature = voltage*100-50;       // 온도값 변환
  
  Serial.print("Temperature : ");           // 온도값 출력
  Serial.println(temperature);
  
  if(temperature > 120)                     // 온도가 120도를 초과하면 LED를 켬
    digitalWrite(13, HIGH);
  else                                      // 온도가 120도 미만이면 LED를 끔
    digitalWrite(13, LOW);
}
