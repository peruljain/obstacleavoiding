int leftsensorecho = 11;
int leftsensortrig = 6;
int middlesensorecho = 8;
int middlesensortrig = 7;
int rightsensorecho = 13;
int rightsensortrig = 12;


int leftmotor1 = 5;
int leftmotor2 = 3;
int rightmotor1 = 9;
int rightmotor2 = 10;

long leftduration;
long middleduration;
long rightduration;

float leftdistance ;
float middledistance ;
float rightdistance ;

void forward(){
  analogWrite(leftmotor1,70);
  analogWrite(leftmotor2,0);
  analogWrite(rightmotor1,70);
  analogWrite(rightmotor2,0);
}
void backward(){
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,70);
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,70);
}
void right(){
  analogWrite(leftmotor1,70);
  analogWrite(leftmotor2,0);
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,0);
}
void uturn(){
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,70);
  analogWrite(rightmotor1,70);
  analogWrite(rightmotor2,0);
}
void left(){
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,0);
  analogWrite(rightmotor1,70);
  analogWrite(rightmotor2,0);
}
void stp(){
  analogWrite(leftmotor1,0);
  analogWrite(leftmotor2,0);
  analogWrite(rightmotor1,0);
  analogWrite(rightmotor2,0);
}
 int left_sensor_sur(){
  digitalWrite(leftsensortrig,LOW);
  delay(2);
  digitalWrite(leftsensortrig,HIGH);
  delay(20);
  digitalWrite(leftsensortrig,LOW);
  leftduration = pulseIn(leftsensorecho,HIGH);
  delay(10);
   float left_distance = leftduration*(0.034/2);
  return (float) left_distance;
 }
  int middle_sensor_sur(){
  digitalWrite(middlesensortrig,LOW);
  delay(2);
  digitalWrite(middlesensortrig,HIGH);
  delay(20);
  digitalWrite(middlesensortrig,LOW);
  middleduration = pulseIn(middlesensorecho,HIGH);
  delay(10);
   float middle_distance = middleduration*(0.034/2);
  return (float) middle_distance;
 }
 int right_sensor_sur(){
  digitalWrite(rightsensortrig,LOW);
  delay(2);
  digitalWrite(rightsensortrig,HIGH);
  delay(20);
  digitalWrite(rightsensortrig,LOW);
  rightduration = pulseIn(rightsensorecho,HIGH);
  delay(10);
   float right_distance = rightduration*(0.034/2);
  return (float) right_distance;
 }





void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(leftsensorecho,INPUT);
  pinMode(middlesensorecho,INPUT);
  pinMode(rightsensorecho,INPUT);
   pinMode(leftsensortrig,OUTPUT);
  pinMode(middlesensortrig,OUTPUT);
  pinMode(rightsensortrig,OUTPUT);
  pinMode(leftmotor1,OUTPUT);
  pinMode(leftmotor2,OUTPUT);
  pinMode(rightmotor1,OUTPUT);
  pinMode(rightmotor2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  leftdistance = left_sensor_sur();
  
  middledistance = middle_sensor_sur();
  
  rightdistance = right_sensor_sur();
  
  /*if(middledistance<=5){
    if(rightdistance>leftdistance){
     stp();
     delay(100);
     backward();
     delay(100);
     right();
     delay(2000);
      
    }
    else{
       stp();
     delay(100);
     backward();
     delay(100);
     left();
     delay(2000);
    }
     
 
  }*/
  /*if(middledistance > rightdistance && middledistance > leftdistance){
  forward();
          
}
if( rightdistance>middledistance && rightdistance > leftdistance){
  right();
          
}
if(leftdistance > rightdistance && leftdistance > middledistance){
  left();
          
}*/
if(middledistance > 5 && rightdistance < 20 && leftdistance < 20){
  forward();//forward
  
}
if(middledistance > 5 && rightdistance  >40 && leftdistance > 40){
  forward();//forward
  Serial.print("forward");
}
if(rightdistance > 20 && leftdistance < 20 && middledistance < 5){
  stp();
  delay(300);
 backward();
 delay(500);
  right();
  delay(1500);//right
  forward();
  delay(2000);
  Serial.print("right");
 
}
if(leftdistance > 20 && rightdistance < 20 && middledistance < 5 ){
  stp();
  delay(300);
  backward();
  delay(500);
  left();
  delay(1500);//left
  forward();
  delay(2000);
  
}
if(middledistance < 5 && rightdistance < 20 && leftdistance < 20){

   stp();
   delay(300);
   backward();
   delay(500);
   uturn();
   delay(1000);
   stp();
   delay(100);//u turn;
   forward;
   delay(3000);
}
if( middledistance < 5 && leftdistance > 20 && rightdistance > 20){
  stp();
  delay(300);
 backward();
 delay(500);
  left();
  delay(1500);
  stp();
  delay(100);//5
}
if(leftdistance < 20 && rightdistance > 20 && middledistance > 12){
  stp();
  delay(300);
 backward();
 delay(500);  
  right();
  delay(1500);
  forward();
  delay(2000);
}
if(leftdistance > 20 && rightdistance > 20 && middledistance > 5){
  stp();
  delay(300);
  
  left();
  delay(1500);//cross
  forward();
  delay(3000);
  stp();
  delay(100);
}
if(leftdistance > 20 && middledistance > 5 && rightdistance < 20){
  stp();
  delay(300);
  forward();
  delay(1500);//8
}
//Serial.println(leftdistance);

Serial.println(rightdistance);
Serial.println(leftdistance);
Serial.println(middledistance);
}
