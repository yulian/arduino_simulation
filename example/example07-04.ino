void setup()
{
  Serial.begin(9600);                   // 시리얼 통신 초기화
  
  pinMode(13, OUTPUT);                  // 디지털 13번 핀을 출력모드로 변경
}

void loop()
{
  int input = analogRead(A0);           // 아날로그 신호를 측정
  int output = (float)input/1023*2000;  // 형변환을 통한 연산
  
  Serial.print(input);                  // 아날로그 입력값 출력
  Serial.print('\t');                   // 공백 출력
  Serial.println(output);               // 변환된 출력값 출력
  
  digitalWrite(13, LOW);
  delay(output);                        // 지연시간을 변수로 제어
  digitalWrite(13, HIGH);
  delay(output);                        // 지연시간을 변수로 제어
}

