#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);





int S5V = 50;
int sensorPin = A0;


int sensei = 10;

int bb;

void setup() {
Serial.begin(9600);    
  pinMode(S5V,OUTPUT);
  digitalWrite(S5V, HIGH);
  motor1.setSpeed(20);
  motor1.run(RELEASE);
  
  motor2.setSpeed(20);
  motor2.run(RELEASE);
  // put your setup code here, to run once:
  float bb = analogRead(sensorPin);
 Serial.print("The value was set to :   ");
  Serial.print(bb);  
  
}

void loop() {
  // put your main code here, to run repeatedly:
if   (bb<(analogRead(sensorPin)-sensei)) {
  Serial.println("Light DETECTED !!!!!!!!");
  motor1.setSpeed(20);
  motor2.setSpeed(20);
  motor1.run(FORWARD);
  motor2.run(FORWARD);  
  delay(10);
} 
else{
Serial.println("Dark is there ... me scared ...");
  motor1.setSpeed(0);
  motor2.setSpeed(0);  
  delay(10);
}
}
