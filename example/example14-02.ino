const int melody[] = {    // 음계 별 주파수를 저장한 변수 선언
  262,	// '도'의 주파수
  294,	// '레'의 주파수
  330,	// '미'의 주파수
  349,	// '파'의 주파수
  392,	// '솔'의 주파수
  440,	// '라'의 주파수
  494,	// '시'의 주파수
  523,	// '도'의 주파수
};

const int PIEZO_PIN = 2;  // 피에조 스피커에 연결된 디지털 핀 번호

void setup() {

  for(int i=6; i<=13; i++) {  // 디지털 6번 핀 ~ 13번 핀까지
    pinMode(i, INPUT);        // 디지털 핀을 입력 모드로 설정
  }
  
  Serial.begin(9600);         // 시리얼 통신 초기화
}

void loop() {
  
  // 눌려진 버튼을 구분해 음계를 선택
  int indexOfMelody = readNote();
  
  // 선택된 음계를 200ms동안 재생
  if (indexOfMelody > -1)
    tone(PIEZO_PIN, melody[indexOfMelody], 200);
  
  // 버튼 누르는 시간을 고려한 일정시간 지연
  delay(50);
}

// 눌려진 버튼에 따라 melody 배열의 인덱스를 반환하는 함수
int readNote() {
  int index = -1;                     // 인덱스 초기값
  for(int i=6; i<=13; i++) {          // 디지털 6번 핀 ~ 13번 핀까지
    int buttonValue = digitalRead(i); // 버튼의 입력 값 읽기를 반복
    if(buttonValue == HIGH)           // 버튼이 눌렸다면
      index = i-6;                    // melody의 인덱스 값 계산
  }
  Serial.println(index);              // 시리얼 모니터에 인덱스 값 출력
  return index;                       // 인덱스 값 반환
}

