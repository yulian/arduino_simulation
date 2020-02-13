#include <IRremote.h>

const int MOTOR_PIN_A = 5;      // 왼쪽 DC모터의 빨간색 단자
const int MOTOR_PIN_B = 6;      // 왼쪽 DC모터의 검은색 단자
const int MOTOR_PIN_C = 9;      // 오른쪽 DC모터의 빨간색 단자
const int MOTOR_PIN_D = 10;     // 오른쪽 DC모터의 검은색 단자
const int REMOTE_PIN = 4;       // 적외선 리모컨 제어 단자

IRrecv irrecv(REMOTE_PIN);      // 적외선 센서에 연결된 핀 번호 매핑
decode_results results;         // 수신된 적외선 신호를 저장할 변수

void setup() {
  
  // 적외선 센서 활성화
  irrecv.enableIRIn();
  
  // DC모터와 연결된 디지털 핀을 출력 모드로 설정
  pinMode(MOTOR_PIN_A,  OUTPUT);
  pinMode(MOTOR_PIN_B,  OUTPUT);
  pinMode(MOTOR_PIN_C,  OUTPUT);
  pinMode(MOTOR_PIN_D,  OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  if(irrecv.decode(&results)) {         // 적외선 신호를 해석
    Serial.println(results.value, HEX); // 적외선 신호 값을 출력
    
    // 적외선 신호 값에 따라 모터 제어
    if(results.value == 0xFD8877)       // 2번 버튼을 눌러 전진
      moveForward();
    else if(results.value == 0xFD9867)  // 8번 버튼을 눌러 후진
      moveBackward();
    else if(results.value == 0xFD28D7)  // 4번 버튼을 눌러 좌회전
      turnLeft();
    else if(results.value == 0xFD6897)  // 6번 버튼을 눌러 우회전
      turnRight();
    else                                // 기타 버튼을 눌러 멈춤
      stopMoving();
    
    delay(30);
    irrecv.resume();                    // 다음 신호를 받기 위해 초기화
  }
}

void moveForward() {
  analogWrite(MOTOR_PIN_A, 0);          // 왼쪽 DC모터를 역방향으로 회전
  analogWrite(MOTOR_PIN_B, 255);
  analogWrite(MOTOR_PIN_C, 255);        // 오른쪽 DC모터를 정방향으로 회전
  analogWrite(MOTOR_PIN_D, 0);
}

void moveBackward() {
  analogWrite(MOTOR_PIN_A, 255);        // 왼쪽 DC모터를 정방향으로 회전
  analogWrite(MOTOR_PIN_B, 0);
  analogWrite(MOTOR_PIN_C, 0);          // 오른쪽 DC모터를 역방향으로 회전
  analogWrite(MOTOR_PIN_D, 255);
}

void turnLeft() {
  analogWrite(MOTOR_PIN_A, 0);          // 왼쪽 DC모터를 역방향으로 느리게 회전
  analogWrite(MOTOR_PIN_B, 100);
  analogWrite(MOTOR_PIN_C, 255);        // 오른쪽 DC모터를 정방향으로 빠르게 회전
  analogWrite(MOTOR_PIN_D, 0);
}

void turnRight() {
  analogWrite(MOTOR_PIN_A, 0);          // 왼쪽 DC모터를 역방향으로 빠르게 회전
  analogWrite(MOTOR_PIN_B, 255);
  analogWrite(MOTOR_PIN_C, 100);        // 오른쪽 DC모터를 정방향으로 느리게 회전
  analogWrite(MOTOR_PIN_D, 0);
}

void stopMoving() {
  analogWrite(MOTOR_PIN_A, 0);          // 모든 DC모터의 속도를 0으로 설정
  analogWrite(MOTOR_PIN_B, 0);
  analogWrite(MOTOR_PIN_C, 0);
  analogWrite(MOTOR_PIN_D, 0);
}
