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

const int PIEZO_PIN = 8;  // 피에조 스피커에 연결된 디지털 핀 번호

void setup()
{
  // "도레미파솔라시도"를 순차적으로 출력
  // 음의 길이가 500ms이며, 간격이 500ms가 되도록 지연시간을 줌
  tone(PIEZO_PIN, melody[0], 500); delay(500);
  tone(PIEZO_PIN, melody[1], 500); delay(500);
  tone(PIEZO_PIN, melody[2], 500); delay(500);
  tone(PIEZO_PIN, melody[3], 500); delay(500);
  tone(PIEZO_PIN, melody[4], 500); delay(500);
  tone(PIEZO_PIN, melody[5], 500); delay(500);
  tone(PIEZO_PIN, melody[6], 500); delay(500);
  tone(PIEZO_PIN, melody[7], 500); delay(500);
}

void loop() {
}

