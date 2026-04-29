#include <AFMotor.h>

#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A4

int THRESHOLD = 300;

AF_DCMotor FL(1);
AF_DCMotor BL(2);
AF_DCMotor FR(3);
AF_DCMotor BR(4);

int SPEED = 110;

void setup() {
  Serial.begin(9600);

  FL.setSpeed(SPEED);
  BL.setSpeed(SPEED);
  FR.setSpeed(SPEED);
  BR.setSpeed(SPEED);
}

void stopAll() {
  FL.run(RELEASE);
  BL.run(RELEASE);
  FR.run(RELEASE);
  BR.run(RELEASE);
}

void forwardMove() {
  FL.run(FORWARD);
  BL.run(FORWARD);
  FR.run(FORWARD);
  BR.run(FORWARD);
}

void slightLeft() {
  FL.setSpeed(80);
  BL.setSpeed(80);
  FR.setSpeed(130);
  BR.setSpeed(130);
  forwardMove();
}

void slightRight() {
  FL.setSpeed(130);
  BL.setSpeed(130);
  FR.setSpeed(80);
  BR.setSpeed(80);
  forwardMove();
}

void sharpLeft() {
  FL.run(BACKWARD);
  BL.run(BACKWARD);
  FR.run(FORWARD);
  BR.run(FORWARD);
}

void sharpRight() {
  FL.run(FORWARD);
  BL.run(FORWARD);
  FR.run(BACKWARD);
  BR.run(BACKWARD);
}

void loop() {
  int v1 = analogRead(IR1);
  int v2 = analogRead(IR2);
  int v3 = analogRead(IR3);
  int v4 = analogRead(IR4);
  int v5 = analogRead(IR5);

  int s1 = (v1 < THRESHOLD) ? 1 : 0;
  int s2 = (v2 < THRESHOLD) ? 1 : 0;
  int s3 = (v3 < THRESHOLD) ? 1 : 0;
  int s4 = (v4 < THRESHOLD) ? 1 : 0;
  int s5 = (v5 < THRESHOLD) ? 1 : 0;

  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.print(s3); Serial.print(" ");
  Serial.print(s4); Serial.print(" ");
  Serial.println(s5);

  if (s2 == 1 && s3 == 1 && s4 == 0) {
    slightLeft();
  }
  else if (s3 == 1 && s4 == 1 && s2 == 0) {
    slightRight();
  }
  else if (s3 == 1 && s2 == 1) {
    FL.setSpeed(SPEED);
    BL.setSpeed(SPEED);
    FR.setSpeed(SPEED);
    BR.setSpeed(SPEED);
    forwardMove();
  }
  else if (s1 == 1) {
    sharpLeft();
  }
  else if (s5 == 1) {
    sharpRight();
  }
  else {
    stopAll();
  }

  delay(40);
}