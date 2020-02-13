void setup()
{
  Serial.begin(9600);                       // 시리얼 통신 초기화
}

void loop()
{
  int analogInput = analogRead(A0);         // 온도센서(TMP36) 값 측정
  float voltage = analogInput*5.0/1023.0;   // 전압값 변환
  float temperature = voltage*100-50;       // 온도값 변환
  
  Serial.print("Temperature : ");           // 온도값 출력
  Serial.println(temperature);
}

