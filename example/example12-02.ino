#include <IRremote.h>

const int RED_PIN = 11;
const int GREEN_PIN	= 9;
const int BLUE_PIN = 10;
unsigned long lastValue = 0;

IRrecv irrecv(8);             // 적외선 센서가 연결된 디지털 핀 번호 매핑
decode_results results;       // 수신된 적외선 신호를 저장할 변수

void setup()
{
  irrecv.enableIRIn();        // 적외선 센서 활성화
  pinMode(RED_PIN, OUTPUT);   // 삼색 LED의 핀을 출력모드로 설정
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  if(irrecv.decode(&results)) {           // 적외선 신호를 해석
    Serial.println(results.value, HEX);   // 적외선 신호 값을 출력
    
    if(results.value == 0xFFFFFFFF) {		
      results.value = lastValue;
    }
    
    if(results.value == 0xFD08F7)         // 리모컨의 숫자 1버튼이 눌렸을 때
      printRGB(255, 105, 180);            // 삼색 LED에 "HotPink" 색상 출력
    else if(results.value == 0xFD8877)    // 리모컨의 숫자 2버튼이 눌렸을 때
      printRGB(0, 255, 255);              // 삼색 LED에 "Aqua" 색상 출력
    else if(results.value == 0xFD48B7)    // 리모컨의 숫자 3버튼이 눌렸을 때
      printRGB(0, 255, 0);                // 삼색 LED에 "Green" 색상 출력
    else
      printRGB(0, 0, 0);                  // 기타 다른 버튼이 눌렸을 때 삼색 LED를 끔
    
    delay(30);
    lastValue = results.value;
    irrecv.resume();                      // 다음 신호를 받을 수 있도록 초기화
  }
}

// RGB 코드 값으로 삼색 LED의 색상을 출력하는 함수
void printRGB(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
