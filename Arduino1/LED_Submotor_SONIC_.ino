//초음파 센서의 핀번호를 설정한다.
#include<Servo.h>
Servo servo;
int value =0 ;
int echoPin = 12;
int trigPin = 13;
int led=2;

void setup() {
  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  servo.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  float duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  digitalWrite(trigPin, HIGH);
//  delay(10);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  distance = ((float)(340 * duration) / 10000) / 2;  
  
  Serial.print(distance);
  Serial.println("cm");
  // 수정한 값을 출력
  if(distance<12){
  digitalWrite(led,HIGH);
  servo.write(180);
  }else{
  digitalWrite(led,LOW);
  servo.write(0);
  }
  delay(100);

  

 
  
}
