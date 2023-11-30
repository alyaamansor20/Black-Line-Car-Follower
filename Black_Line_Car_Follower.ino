
#define RightMotor1 2
#define RightMotor2 4
#define LeftMotor1 7 
#define LeftMotor2 8

#define LeftSensor 9
#define MidSensor 10
#define RightSensor 11

#define maxi 500

void setup() {
  pinMode(RightMotor1,OUTPUT);
  pinMode(RightMotor2,OUTPUT);
  pinMode(LeftMotor1,OUTPUT);
  pinMode(LeftMotor2,OUTPUT);
}

void loop() {
  int leftRead = analogRead(LeftSensor);
  int midRead = analogRead(MidSensor);
  int rightRead = analogRead(RightSensor);
  
  if(midRead > maxi)
    forward();
  if(leftRead > maxi && rightRead < maxi)
    left();
  else if (leftRead < maxi && rightRead > maxi) 
    right();

  if(leftRead < maxi && rightRead < maxi && midRead < maxi)
    stopMove();
}

void forward(){
  digitalWrite(RightMotor1, 1);
  digitalWrite(RightMotor2, 0);
  digitalWrite(LeftMotor1, 1);
  digitalWrite(LeftMotor2, 0);
}

void left(){
  digitalWrite(RightMotor1, 1);
  digitalWrite(RightMotor2, 0);
  digitalWrite(LeftMotor1, 0);
  digitalWrite(LeftMotor2, 1);
}

void right(){
  digitalWrite(RightMotor1, 0);
  digitalWrite(RightMotor2, 1);
  digitalWrite(LeftMotor1, 1);
  digitalWrite(LeftMotor2, 0);
}

void stopMove(){
  digitalWrite(RightMotor1, 0);
  digitalWrite(RightMotor2, 0);
  digitalWrite(LeftMotor1, 0);
  digitalWrite(LeftMotor2, 0);
}
