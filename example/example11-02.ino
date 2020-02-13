// 아두이노의 디지털 핀과 7세그먼트 연결
#define	A	4
#define	B	5
#define C	12
#define D	11
#define	E	10
#define	F	3
#define G	2
#define	DP	13

int digit[10][8] = {
//A, B, C, D, E, F, G, DP
  0, 0, 0, 0, 0, 0, 1, 1,	// 숫자 0을 표현
  1, 0, 0, 1, 1, 1, 1, 1,	// 숫자 1을 표현
  0, 0, 1, 0, 0, 1, 0, 1,	// 숫자 2를 표현
  0, 0, 0, 0, 1, 1, 0, 1,	// 숫자 3을 표현
  1, 0, 0, 1, 1, 0, 0, 1,	// 숫자 4를 표현
  0, 1, 0, 0, 1, 0, 0, 1,	// 숫자 5를 표현
  0, 1, 0, 0, 0, 0, 0, 1,	// 숫자 6을 표현
  0, 0, 0, 1, 1, 1, 1, 1,	// 숫자 7을 표현
  0, 0, 0, 0, 0, 0, 0, 1,	// 숫자 8을 표현
  0, 0, 0, 1, 1, 0, 0, 1	// 숫자 9를 표현
};


void setup() {
  
  // 7세그먼트와 연결된 디지털 핀을 출력 모드로 설정
  pinMode(A,  OUTPUT);
  pinMode(B,  OUTPUT);
  pinMode(C,  OUTPUT);
  pinMode(D,  OUTPUT);
  pinMode(E,  OUTPUT);
  pinMode(F,  OUTPUT);
  pinMode(G,  OUTPUT);
  pinMode(DP, OUTPUT);
}

void loop() {
  
  // 7세그먼트로 0부터 9까지 숫자 출력
  displayDigit(digit[0]); delay(1000);
  displayDigit(digit[1]); delay(1000);
  displayDigit(digit[2]); delay(1000);
  displayDigit(digit[3]); delay(1000);
  displayDigit(digit[4]); delay(1000);
  displayDigit(digit[5]); delay(1000);
  displayDigit(digit[6]); delay(1000);
  displayDigit(digit[7]); delay(1000);
  displayDigit(digit[8]); delay(1000);
  displayDigit(digit[9]); delay(1000);
}

// 7세그먼트로 숫자를 표시하는 함수
void displayDigit(int *digit) {
  digitalWrite(A,  digit[0]);
  digitalWrite(B,  digit[1]);
  digitalWrite(C,  digit[2]);
  digitalWrite(D,  digit[3]);
  digitalWrite(E,  digit[4]);
  digitalWrite(F,  digit[5]);
  digitalWrite(G,  digit[6]);
  digitalWrite(DP, digit[7]);
}

