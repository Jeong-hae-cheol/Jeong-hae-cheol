// 모터 A
 
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// 모터 B
 
int enB = 3;
int in3 = 5;
int in4 = 4;
 
void setup()
 
{
 //모터 컨트롤 핀을 OUTPUT으로 설정


  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
}
  
void demoOne()  // 방향전환 테스트
 
{
  // 전진

  // 모터 A 실행
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
 
  // 모터 속도 200으로 설정 (0~255)
 
  analogWrite(enA, 200);
 
  // 모터 B 실행
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  // 모터 속도 200으로 설정 (0~255)
 
  analogWrite(enB, 200);
 
  delay(2000);
 
  // 후진
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
 
  delay(2000);
 
  // 종료
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
}
 
void demoTwo() //모터 속도 테스트
 
{
  // 모터 실행
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
 
  // 0 -> 255로 가속
 
  for (int i = 0; i < 256; i++)
 
  {
 
    analogWrite(enA, i);
    analogWrite(enB, i);
 
    delay(20);
 
  } 
 
  // 255 -> 0 으로 서서히 감속
 
  for (int i = 255; i >= 0; --i)
 
  {
 
    analogWrite(enA, i);
    analogWrite(enB, i);
 
    delay(20);
 
  } 
 
  // 종료
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
 
}
 
void loop()
 
{
 
  demoOne();
 
  delay(1000);
 
  demoTwo();
 
  delay(1000);

}
