#include <LiquidCrystal.h>

// 아두이노 연결된 핀번호로 LCD모듈 초기화
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);       // 1062 LCD모듈 설정
  Serial.begin(9600);     // 시리얼 통신 초기화
}

void loop() {
  int readValue = analogRead(A0);         // 온도센서(TMP36) 값 측정
  float voltage = readValue*5.0/1024.0;   // 전압 값 변환
  float temperature = voltage*100-50;     // 온도 값 변환
  String tempStr = String(temperature);   // 온도 값을 문자열로 변환
  lcd.print("TEMP: " + tempStr);          // LCD에 문자열 출력
  Serial.println(tempStr);                // 시리얼 모니터에 문자열 출력
  
  delay(500);     // 500ms(밀리초) 지연
  lcd.clear();    // LCD 초기화
}
