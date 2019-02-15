#include <Servo.h> 

const int trigPin = 9;
const int echoPin = 10;
int bz=13,led=8;

int c=0;
long duration;
int distance;

Servo myServo;
 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(led, OUTPUT);
  pinMode(echoPin, INPUT); 
   pinMode(bz, OUTPUT); 
  Serial.begin(9600);
  myServo.attach(11); 
}

void loop() {  
  // rotates the servo motor from 20 to 160 degrees
  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(30);
  digitalWrite(13,LOW);
  digitalWrite(led,LOW);
  distance = calculateDistance();  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print(".");
  
if(distance<51){
  c=0;
 PlaySound(5);
      }
  }


  // Repeats the previous lines from 160 to 20 degrees
  for(int i=180;i> 0;i--){  
  myServo.write(i);
  delay(30);
  digitalWrite(13,LOW);
  digitalWrite(led,LOW);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  
if(distance<51){
  c=0;
  PlaySound(5);
      }
  }

}
//****************** calculating the distance measured by the Ultrasonic sensor ****************

int calculateDistance(){   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}

void PlaySound(int times){
  c++;
if(c<50){
  digitalWrite(bz,HIGH);
  digitalWrite(led,HIGH);
}  
  }

