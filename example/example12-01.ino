#include <IRremote.h>

IRrecv irrecv(8);         // 적외선 센서가 연결된 디지털 핀 번호 매핑
decode_results results;   // 수신된 적외선 신호를 저장할 변수

void setup() {
  irrecv.enableIRIn();    // 적외선 센서 활성화
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(irrecv.decode(&results)) {         // 적외선 신호를 해석
    Serial.println(results.value, HEX); // 적외선 신호 값을 출력
    
    if(results.value == 0xFD30CF) {     // 숫자 0 버튼이 눌리면 LED를 켬
      digitalWrite(9, HIGH);            // 다른 버튼이 눌리면 LED를 끔
    }
    else {
      digitalWrite(9, LOW);
    }
    
    delay(30);
    irrecv.resume();                    // 다음 신호를 받을 수 있도록 초기화
  }
}

