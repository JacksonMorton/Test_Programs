 #include <Servo.h>
 
 Servo servo1; 
 Servo servo2;
 
 boolean feedback_on = true;
 int feedback1 = 0; int feedback1_map;
 int feedback2 = 0; int feedback2_map;
 uint8_t feedbackPin1 = A0; 
 uint8_t feedbackPin2 = A1;
 
 int i; int u; int z;
 int mode_switch = 12;
 boolean lastMode;
 boolean manual;
 
 int initial_delay = 2000;
 int x = 1; int y = 2;
 
 int testValues[] = {45,60,75,90,105,120,135};
 
 /************************************/ 

 void setup() {
   
  servo1.attach(10,1000,2000);
  servo2.attach(9,1000,2000);

  feedback1 = analogRead(feedbackPin1); 
  feedback2 = analogRead(feedbackPin2);

  pinMode(mode_switch, INPUT);
  lastMode != digitalRead(mode_switch);
 
  servo1.write(90);
  servo2.write(90);

  Serial.begin(9600);
  Serial.println("Beginning test program..."); Serial.println("");
  delay(initial_delay);
  
  
 }
 
 void loop() {
   
  servo1_test();
  
 }
