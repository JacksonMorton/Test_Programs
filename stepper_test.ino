
/**************************************************************************/

 void sum_steps(){
   if(outputDir) {netSteps = netSteps + i;}
     else{netSteps = netSteps - i;}
 }
 
 /**************************************************************************/

 int angles_to_steps() {
   servo_x(90); servo_y(90);
   long totalSteps = 3200;  // The number of steps in one full revolution of the stepper motor.
   for (int j=0; j < (sizeof(stepperValues)/sizeof(int)); j++) {
     stepsArray[j] = stepperValues[j] * totalSteps / 360;
     Serial.print("stepsArray["); Serial.print(j); Serial.print("]:  "); Serial.println(stepsArray[j]);
   }
   Serial.println("");
 }
 
 /**************************************************************************/

 void stepper_position(int a) {
  
   if(a < netSteps) {digitalWrite(dir,LOW); outputDir = false;}
     else {digitalWrite(dir, HIGH); outputDir = true;}
    
   for(i=0; i < abs(netSteps-a); i++) {
     digitalWrite(steps,LOW);
     digitalWrite(steps,HIGH);
     delayMicroseconds(stepperSpeed);
   }
   sum_steps();
 }     
 
 /**************************************************************************/

 void stepper_test() {
  angles_to_steps();
      
  toggleSwitch(z);
  Serial.println("Done with loop!");
 }




