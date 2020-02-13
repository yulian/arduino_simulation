#include <LiquidCrystal.h>

// 아두이노 연결된 핀번호로 LCD모듈 초기화
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);               // 1062 LCD모듈 설정
  lcd.print("Hello, Arduino!!");  // 문자 출력
}

void loop() {
  lcd.setCursor(0, 1);            // 커서의 위치를 변경
  lcd.print("1234567890");        // 숫자 출력
}

