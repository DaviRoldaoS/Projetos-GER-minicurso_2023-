//Arduino number15 funciona
#include <Servo.h>
#define catraca A0
#define trigger 11 
#define echo A1
#define vermelho 13
#define verde 12
Servo servo;
int distancia = 0;


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(trigger, OUTPUT);  // Clear the trigger
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  pinMode(echo, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echo, HIGH);
}
void setup() {
  servo.write(180);
pinMode(vermelho, OUTPUT);
pinMode(verde, OUTPUT);
servo.attach(catraca);
Serial.begin(9600);
}

void loop() {
  distancia = 0.01723*readUltrasonicDistance(trigger, echo);
  Serial.println(distancia);
  if (distancia<10){
    digitalWrite(verde, HIGH);
    digitalWrite(vermelho, LOW);
    servo.write(90);
  }
  else {
    digitalWrite(verde, LOW);
    digitalWrite(vermelho, HIGH);
    servo.write(180);
  }
  delay(500);
}