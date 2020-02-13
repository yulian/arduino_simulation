const int MOTOR_PIN_A = 5;    // DC 모터의 빨간색 단자
const int MOTOR_PIN_B = 6;    // DC 모터의 검은색 단자

void setup() {
  
  // DC 모터와 연결된 디지털 핀을 출력 모드로 설정
  pinMode(MOTOR_PIN_A,  OUTPUT);
  pinMode(MOTOR_PIN_B,  OUTPUT);
}

void loop() {
  
  // 푸시버튼의 입력 값을 readValue에 저장
  int readValue = digitalRead(4);
  
  // 푸시버튼의 눌림 여부에 따라 DC 모터의 방향 제어
  if(readValue == LOW) {
    analogWrite(MOTOR_PIN_A, 255);
    analogWrite(MOTOR_PIN_B, 0);
  }
  else {
    analogWrite(MOTOR_PIN_A, 0);
    analogWrite(MOTOR_PIN_B, 255);
  }
}

