void setup()
{
  Serial.begin(9600);
  
  pinMode(8, OUTPUT);
  pinMode(7, INPUT_PULLUP);   // 내부 풀업저항을 사용하도록 설정
}

void loop()
{
  int readValue = digitalRead(7);
  Serial.println(readValue);
  
  if(readValue == HIGH) {
    digitalWrite(8, LOW);
  }
  else {
    digitalWrite(8, HIGH);
  }
}

