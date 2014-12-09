
 #include <Servo.h>
 #include <MemoryFree.h>
 
 boolean feedback_on = true;
 boolean lastMode;
 boolean manual;
 int i; int u; int w;
 int mode_switch = 12;
 int feedback1 = 0; int feedback1_map;
 int feedback2 = 0; int feedback2_map;
 uint8_t feedbackPin1 = A0; 
 uint8_t feedbackPin2 = A1;
 int initial_delay = 2000;

  /* ----- servo1_test & servo2_test Variables ----- */
 
 Servo servo1; 
 Servo servo2;
 int testValues[] = {60,75,90,105,120};
 long x_false; long y_false;
 int x = 1; int y = 2; int z = 3;
  
  /* ----- servos_test Variables ----- */
 
 //int testAngles[11] = {60,66,72,78,84,90,96,102,108,114,120};  // Define test angle array.
 boolean servos_test_feedback = false;
 int testAngles[10] = {60,66,72,78,84,90,96,102,111,120};
 int n = sizeof(testAngles) / sizeof(int);  // n = # of angles in testAngle[] array.
 struct AnglePair{
   int angleX;
   int angleY; };
 AnglePair randomPositionsArray[100];
 int randomArray[100]; 
 int val1; int val2;
 
 /* ----- stepper_test Variables ----- */
 
 boolean moveStepper = true;
 int dir = 2;
 int steps = 3;
 int netSteps = 0;
 boolean outputDir = false;
 int stepperValues[] = {-15,-10,-5,0,5,10,15};
 int stepsArray[5];
 int stepperSpeed = 1000;
 
 /*************************************************/ 

 void setup() {
   
  servo1.attach(10,1000,2000);
  servo2.attach(9,1000,2000);
  pinMode(dir, OUTPUT);
  pinMode(steps, OUTPUT);

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
   //servo1_test();
   //servo2_test();
   //servos_test();
   stepper_test();
  
 }
