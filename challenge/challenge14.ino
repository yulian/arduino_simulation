const int melody[] = {      // 음계 별 주파수를 저장한 변수 선언
  262,	// '도'의 주파수
  294,	// '레'의 주파수
  330,	// '미'의 주파수
  349,	// '파'의 주파수
  392,	// '솔'의 주파수
  440,	// '라'의 주파수
  494,	// '시'의 주파수
  523,	// '도'의 주파수
};

const int PIEZO_PIN = 8;    // 피에조 스피커에 연결된 디지털 핀 번호
const int BASE = 200;       // 기본음 길이

void setup()
{
  // 솔솔솔파미
  tone_with_delay(melody[4], BASE);
  tone_with_delay(melody[4], BASE);
  tone_with_delay(melody[4], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[2], BASE*4);
  
  delay(BASE*2);
  
  // 파파파미레
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[1], BASE*4);
  
  delay(BASE*2);
  
  // 미미미파미도레
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[0], BASE);
  tone_with_delay(melody[1], BASE*6);
  
  delay(BASE*2);
  
  // 솔솔솔파미
  tone_with_delay(melody[4], BASE);
  tone_with_delay(melody[4], BASE);
  tone_with_delay(melody[4], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[2], BASE*4);
  
  delay(BASE*2);
  
  // 파파파미레
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[1], BASE*4);
  
  delay(BASE*2);
  
  // 미미미파미레도
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[3], BASE);
  tone_with_delay(melody[2], BASE);
  tone_with_delay(melody[1], BASE);
  tone_with_delay(melody[0], BASE*6);
}

void loop()
{

}

// 음의 지속시간과 간격을 주기위한 함수
void tone_with_delay(int frequency, int duration)
{
  tone(PIEZO_PIN, frequency, duration);
  delay(duration*1.3);
}

