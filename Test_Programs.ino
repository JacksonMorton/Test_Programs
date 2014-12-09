
 #include <Servo.h>
 #include <MemoryFree.h>
 
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
 
 long x_false; long y_false;
 
 int testValues[] = {60,75,90,105,120};
 
 boolean servos_test_feedback = false;
 
 //int testAngles[11] = {60,66,72,78,84,90,96,102,108,114,120};  // Define test angle array.
 int testAngles[10] = {60,66,72,78,84,90,96,102,111,120};
 int n = sizeof(testAngles) / sizeof(int);  // n = # of angles in testAngle[] array.

 struct AnglePair{
   int angleX;
   int angleY; };
 //AnglePair randomPositionsArray2[25];
 AnglePair randomPositionsArray[100];
 int randomArray[100]; 
 int val1; int val2;
 
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
   
  servos_test();
  //build_positionsArray();
  
 }
