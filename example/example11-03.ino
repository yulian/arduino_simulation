// 아두이노의 디지털 핀과 7세그먼트 디코더(CD4511) 연결
//               DIN CIN BIN AIN
int dataPin[4] = {7,  6,  5,  4};	

int digit[10][4] = {
//DIN, CIN, BIN, AIN
   0,   0,   0,   0,	// 숫자 0을 표현
   0,   0,   0,   1,	// 숫자 1을 표현
   0,   0,   1,   0,	// 숫자 2를 표현
   0,   0,   1,   1,	// 숫자 3을 표현
   0,   1,   0,   0,	// 숫자 4를 표현
   0,   1,   0,   1,	// 숫자 5를 표현
   0,   1,   1,   0,	// 숫자 6을 표현
   0,   1,   1,   1,	// 숫자 7을 표현
   1,   0,   0,   0,	// 숫자 8을 표현
   1,   0,   0,   1,	// 숫자 9를 표현
};


void setup() {
  
  // 7세그먼트 디코더와 연결된 디지털 핀을 출력 모드로 설정
  for(int i=0; i<4; i++)
    pinMode(dataPin[i], OUTPUT);
}

void loop() {
  
  // 7세그먼트 디코더로 0부터 9까지 숫자 출력
  for(int i=0; i<10; i++) {
    displayDigit(dataPin, digit[i]);
    delay(1000);
  }
}

// 7세그먼트 디코더로 숫자를 표시하는 함수
void displayDigit(int *dataPin, int *digit) {
  digitalWrite(dataPin[0],  digit[0]);	// DIN의 값 매핑
  digitalWrite(dataPin[1],  digit[1]);	// CIN의 값 매핑
  digitalWrite(dataPin[2],  digit[2]);	// BIN의 값 매핑
  digitalWrite(dataPin[3],  digit[3]);	// AIN의 값 매핑
}

