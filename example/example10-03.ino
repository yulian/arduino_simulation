#include <LiquidCrystal.h>

// 아두이노 연결된 핀번호로 LCD모듈 초기화
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);               // 1062 LCD모듈 설정
  lcd.print("Hello, Arduino!!");  // 문자 출력
}

void loop() {
  
  // 출력된 문자를 왼쪽으로 16칸(문자길이) 이동
  for(int position=0; position<16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  
  // 출력된 문자를 오른쪽으로 32칸(문자길이 + LCD의 가로길이) 이동
  for(int position=0; position<32; position++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  
  // 출력된 문자를 왼쪽으로 16칸(문자길이) 이동
  for(int position=0; position<16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}


 
