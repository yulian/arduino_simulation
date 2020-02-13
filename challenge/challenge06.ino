int flag = 0;                         // 상태를 구분하기 위한 변수

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
}

void loop()
{
  int inputValue = digitalRead(7);
  
  if (inputValue == HIGH) {           // 푸시버튼이 눌렸을 때
    if (flag == 0)                    // 꺼짐 상태이면 켜짐 상태로 변경
      flag = 1;
    
  } else {                            // 푸시버튼이 떼어졌을 때
    if (flag == 1) {
      int ledStatus = digitalRead(8); // 현재 LED의 상태를 읽음
      if (ledStatus == HIGH)          // LED의 상태가 켜짐이면 꺼짐으로 변경
        digitalWrite(8, LOW);
      else                            // LED의 상태가 꺼짐이면 켜짐으로 변경
        digitalWrite(8, HIGH);			
      flag = 0;                       // 상태 구분 변수를 초기화
    }
  }
  delay(100);                         // 100ms 지연시간
}


