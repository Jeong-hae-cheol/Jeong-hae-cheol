// 컨트롤러
int ch1;
int ch2;

// 모터 A

int enA = 9;
int in1 = 8;
int in2 = 7;
 
// 모터 B
 
int enB = 3;
int in3 = 5;
int in4 = 4;

// 모터속도 0으로 초기화
 
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;

void setup()
{
  //컨트롤러 핀을 INPUT으로 설정
  Serial.begin(9600); 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  //모터 컨트롤 핀을 OUTPUT으로 설정 
 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
   
  // 모터 비활성화 상태에서 전진 방향으로 시작
  
  // 모터 A
  
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // 모터 B
  
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void loop()
{
  //컨트롤러에서 보내는 신호를 A0,A1에서 받는다
  ch1 = pulseIn(A0,HIGH);
  ch2 = pulseIn(A1,HIGH);

  //시리얼모니터에 모터속도 표기
  Serial.print(MotorSpeed1);Serial.print("<-모터1\n");
  Serial.print(MotorSpeed2);Serial.print("<-모터2\n");
  Serial.print('\n');
  
 

 
  if(ch1 > 1500) //전진
  {
     // 모터A 전진
 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
 
    // 모터B 전진
 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    //모터 속도 결정
    
    MotorSpeed1 = map(ch1, 1490, 2020, 0, 255);
    MotorSpeed2 = MotorSpeed1;

    
 
  }
  else if(ch1 < 1450) //후진
  {
    // 모터A 후진
 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
 
    // 모터B 후진
 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);


    //모터 속도 결정
    ch1 = ch1 - 1450;
    ch1 = ch1 * -1;
    MotorSpeed1 = map(ch1, 0, 280, 0, 255);
    MotorSpeed2 = map(ch1, 0, 280, 0, 255);
  }
  else
  {
    // 정지
 
    MotorSpeed1 = 0;
    MotorSpeed2 = 0; 
  }

  if(ch2 < 1360) // 모터A 감속 모터B 가속(좌회전)
  {
    ch2 = ch2 - 1360;
    ch2 = ch2 * -1;

    ch2 = map(ch2, 0, 440, 0, 255);

    MotorSpeed1 = MotorSpeed1 - ch2;
    MotorSpeed2 = MotorSpeed2 + ch2;

    if(MotorSpeed1 < 0)MotorSpeed1 = 0;
    if(MotorSpeed2 > 255)MotorSpeed2 = 255;
  }
  else if(ch2 > 1410) // 모터A 가속 모터B 감속(우회전)
  {
    ch2 = map(ch2, 1410, 1920, 0, 255);

    MotorSpeed1 = MotorSpeed1 + ch2;
    MotorSpeed2 = MotorSpeed2 - ch2;

    if(MotorSpeed1 > 255)MotorSpeed1 = 255;
    if(MotorSpeed2 < 0)MotorSpeed2 = 0;
  }

  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2);
}
