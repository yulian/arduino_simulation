#include <IRremote.h>

IRrecv irrecv(8);         // 적외선 센서가 연결된 디지털 핀 번호 매핑
decode_results results;   // 수신된 적외선 신호를 저장할 변수
int brightness = 0;       // 밝기를 제어하는 변수

void setup() {
  irrecv.enableIRIn();    // 적외선 센서 활성화
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(irrecv.decode(&results)) {           // 적외선 신호를 해석
    Serial.print(results.value, HEX);     // 적외선 신호 값을 출력
    Serial.print("\t");                   // 공백 출력
    Serial.println(brightness);           // 밝기 변수값 출력
    
    if(results.value == 0xFD08F7) {       // 숫자 1 버튼이 눌리면 LED를 어둡게
      brightness-=10;
      if(brightness<0)
        brightness=0;
      analogWrite(9, brightness);
    }
    else if(results.value == 0xFD8877) {  // 숫자 2 버튼이 눌리면 LED를 밝게
      brightness+=10;
      if(brightness>255)
        brightness=255;
      analogWrite(9, brightness);
    }
    
    delay(30);
    irrecv.resume();    // 다음 신호를 받을 수 있도록 초기화
  }
}

