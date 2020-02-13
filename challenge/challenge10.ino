#include <LiquidCrystal.h>

// 문자열을 초기화
String str = String("Nice to meet you!! Arduino");

// 아두이노 연결된 핀번호로 LCD모듈 초기화
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);		// 1062 LCD모듈 설정
  lcd.print(str);		// 문자 출력
}

void loop() {
  
  // 문자열의 길이를 가져와 변수에 저장
  int length = str.length();
  
  // 출력된 문자를 왼쪽으로 (문자길이 - LCD의 가로길이)만큼 이동
  for(int position=0; position<length-16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  
  // 출력된 문자를 오른쪽으로 문자의 길이만큼 이동
  for(int position=0; position<length; position++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  
  // 출력된 문자를 왼쪽으로 문자의 길이만큼 이동
  for(int position=0; position<length; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
}

