#define EN        8  

//Direction pin
#define X_DIR     5


//Step pin
#define X_STP     2


//DRV8825
int delayTime=100; //Delay between each pause (uS)
int stps=6400;// Steps to move



int rotate(int cycles, bool directionBool = false, int delayMicros = 600){
  /*Add argument to controll step width*/
  digitalWrite(X_DIR, directionBool);

  int oneTurnSteps = 96;

  int cyclesLeft = cycles;

  /*
  if (cycles > 1){
    cyclesLeft -= 1;
    for (int _i = 0; _i <= oneTurnSteps; _i ++){
      digitalWrite(X_STP, HIGH);
      delayMicroseconds(delayMicros + 200);
      digitalWrite(X_STP, LOW);ss
      delayMicroseconds(delayMicros + 200);
    }
  }
  */
  int initialStartupDelay = 4000;
  for (int _i = 0; _i <= 10; _i ++){
    digitalWrite(X_STP, HIGH);
    delayMicroseconds(initialStartupDelay);
    digitalWrite(X_STP, LOW);
    delayMicroseconds(delayMicros);
    initialStartupDelay -= 400;
  }
  
  
  for (int _i = 0; _i <= (cyclesLeft * oneTurnSteps)-10; _i++){
    digitalWrite(X_STP, HIGH);
    delayMicroseconds(delayMicros);
    digitalWrite(X_STP, LOW);
    delayMicroseconds(delayMicros);
  }
  return(0);
}

void rotateInfinite(bool directionBool = false, int delayMicros = 700){
  while(true){
    rotate(1, directionBool, delayMicros);
  }
}

void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  delay(50);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(delayTime);
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(delayTime*20);
  }
}

void setup(){
  pinMode(X_DIR, OUTPUT);
  pinMode(X_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(EN, LOW);
}

void loop(){
  //rotateInfinite(true);
  rotate(10);
  delay(5000);

}
