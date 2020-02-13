void setup()
{
  Serial.begin(9600);                   // 시리얼 통신 초기화
  pinMode(13, OUTPUT);                  // 디지털 13번 핀을 출력모드로 설정
}

void loop()
{
  int photoresistor = analogRead(A0);   // 조도센서 값 측정
  Serial.println(photoresistor);        // 조도센서 값 출력
  
  if(photoresistor > 100)
    digitalWrite(13, HIGH);             // 어두울 때 가로등의 불빛을 켬
  else
    digitalWrite(13, LOW);              // 밝을 때 가로등의 불빛을 끔
}

