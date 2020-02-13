int flag            = 0;	// 버튼의 릴리즈 상태를 구분
int colorSelection  = 0;	// 0:빨강(R), 1:초록(G), 2:파랑(B)
int redValue        = 0;	// 빨간색 값(0~255)
int greenValue      = 0;	// 초록색 값(0~255)
int blueValue       = 0;	// 파란색 값(0~255)

void setup()
{
  // 삼색 LED의 핀 모드 설정
  pinMode(11, OUTPUT);		// 디지털 11번 핀: 빨강(R)
  pinMode(9, OUTPUT);		// 디지털 9번 핀: 초록(G)
  pinMode(10, OUTPUT);		// 디지털 10번 핀: 파랑(B)
  
  // 버튼에 대한 입력모드 설정
  pinMode(8, INPUT);
  
  // 시리얼 모니터에 출력을 위한 초기화
  Serial.begin(9600);
}

void loop()
{
  // 버튼을 누를때마다 R, G, B의 상태 변경
  int inputValue = digitalRead(8);
  if (inputValue == HIGH) {	
    if (flag == 0)
      flag = 1;
  } else {
    if (flag == 1) {
      colorSelection++;
      Serial.println("Color is changed!!!");
      if(colorSelection > 2)
        colorSelection = 0;
      flag = 0;
    }
  }
  
  // 가변저항으로 변경한 값을 임시로 저장
  int readValue = analogRead(A0);
  int colorLevel = map(readValue, 0, 1023, 0, 255);
  if (colorSelection == 0)
    redValue = colorLevel;
  else if (colorSelection == 1)
    greenValue = colorLevel;
  else
    blueValue = colorLevel;
    
  // 가변저항으로 변경한 R, G, B 값을 삼색 LED에 적용
  analogWrite(11, redValue);
  analogWrite(9, greenValue);
  analogWrite(10, blueValue);
  
  // 시리얼 모니터에 R, G, B 값 출력
  Serial.print("R:");
  Serial.print(redValue);
  Serial.print("\tG:");
  Serial.print(greenValue);
  Serial.print("\tB:");
  Serial.println(blueValue);
  
  delay(100);
}

