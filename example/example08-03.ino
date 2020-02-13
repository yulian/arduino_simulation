void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int readValue = analogRead(A0);
  
  // map() 함수를 이용해 입력 값의 범위를 변경
  int convertedValue = map(readValue, 0, 1023, 0, 255);
  analogWrite(9, convertedValue);
  
  // 시리얼 모니터로 가변저항의 값과 범위 변경된 값을 출력
  Serial.print(readValue);
  Serial.print("\t");
  Serial.println(convertedValue);
}

