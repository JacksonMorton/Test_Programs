  
  
  void toggleSwitch(int motor) {
    
  if (motor == x || motor == y){
    for(i=0; i < (sizeof(testValues)/sizeof(int)); i++) {
      //Serial.print("lastMode: "); Serial.print(lastMode); Serial.print("   manual: "); Serial.print(manual);
      manual = digitalRead(mode_switch);
      feedback_on = true;
      
      while (lastMode == manual) {
        //Serial.println("manual: "); Serial.println(manual);
        if (motor == x) {
          servo_x(u);
          servo_y(90); 
          w = x;}
        else if (motor == y) {
          servo_x(90);
          servo_y(u);
          w = y; }
        manual = digitalRead(mode_switch);
       
        if (feedback_on){
          delay(1500);
          feedback();
        }
      } 
      u = testValues[i];
      lastMode = manual;
    }
  }
  else {
    servo_x(90); 
    servo_y(90);
    stepsArray[6] = 133;
    for(int h=0; h < (sizeof(stepperValues)/sizeof(int)); h++) {
      manual = digitalRead(mode_switch);
      //Serial.print("manual "); Serial.println(manual);
      
      while (lastMode == manual) {
        if (moveStepper) {
          Serial.print("stepsArray["); Serial.print(h); Serial.print("] = ");Serial.println(stepsArray[h]);
          //Serial.print("h = "); Serial.println(h);
          //Serial.print("stepsArray[6]: "); Serial.println(stepsArray[6]);
          
          //Serial.print("stepsArray[6]: "); Serial.println(stepsArray[6]);
            stepper_position(stepsArray[h]); 
          //Serial.print("netSteps:  "); Serial.println(netSteps); Serial.println("");
          moveStepper = false;  
        }
        manual = digitalRead(mode_switch); 
      }
      
    lastMode = manual;
    moveStepper = true;
    }
    
  }
  
}
  
  
  /**************************************************************************/
  
  
  void feedback() {
    feedback1 = analogRead(feedbackPin1); feedback2 = analogRead(feedbackPin2);
    feedback1_map = map(feedback1, 259, 356, 45, 135); feedback2_map = map(feedback2, 245, 340, 45, 135);
    Serial.println("");
    if (w == x) {
    Serial.print("servo1 feedback: "); Serial.print(feedback1); Serial.println(" (This number is between 263 and 360.)");
    Serial.print("servo1 mapped feedback: "); Serial.print(feedback1_map); Serial.println(" degrees"); }
    else if (w == y) {
    Serial.print("servo2 feedback: "); Serial.print(feedback2); Serial.println(" (This number is between 252 and 342.)");
    Serial.print("servo2 mapped feedback: "); Serial.print(feedback2_map); Serial.println(" degrees"); }
    Serial.println(""); Serial.println(""); 
    feedback_on = false;
  }
  
  
  /**************************************************************************/
  
  
  void center() {
 
  servo_x(90);
  servo_y(90);
  
  feedback1 = analogRead(feedbackPin1); feedback2 = analogRead(feedbackPin2);
  feedback1_map = map(feedback1, 262.4, 360.2, 67.82, 112.8); feedback2_map = map(feedback2, 249.8, 342, 68.83, 111.24);
  Serial.println("");
  Serial.print("servo1 feedback: "); Serial.print(feedback1); Serial.println(" (This number is between 262 and 360.)");
 // Serial.print("servo1 mapped feedback: "); Serial.print(feedback1_map); Serial.println(" degrees"); 
  Serial.print("servo2 feedback: "); Serial.print(feedback2); Serial.println(" (This number is between 250 and 342.)");
 // Serial.print("servo2 mapped feedback: "); Serial.print(feedback2_map); Serial.println(" degrees"); 
  Serial.println(""); Serial.println(""); 
 
  if(netSteps > 0) {digitalWrite(dir,LOW); outputDir = false;}
    else {digitalWrite(dir,HIGH); outputDir = true;}
  for(i=0; i < abs(netSteps); i++){
    digitalWrite(steps,LOW);
    digitalWrite(steps,HIGH);
    delayMicroseconds(n);
  } 
  sum_steps();
  delay(3000);
  }
  
  
  /**************************************************************************/
  
  
  //void servo_x(long x_val) {
  void servo_x(long x_val) {
    x_false = (x_val - 45.382) / 0.4987;
    servo1.write(x_false);  // This line of code causes an error in toggleSwitch() 
                            // when the stepper motor is tested.
  }
  
  void servo_y(long y_val) {
    y_false = (y_val - 47.618) / 0.4713;
    servo2.write(y_false); 
  }
  
  
  /**************************************************************************/


 void build_positionsArray() { //Creat the complete, ordered array of every test angle.

   //Serial.print("freeMemory: "); Serial.println(freeMemory());

   //struct AnglePair{
   //int angleX;
   //int angleY; };

   if (servos_test_feedback) {Serial.print("n = "); Serial.println(n); } 
   
   AnglePair testPair;  //  Define the varialbe "testPair" as a struct of the type "anglePair".
   
   AnglePair positionsArray[n*n];  // Define "positionsArray[]" as an array with n^2 elements, where each element is a testPair.
   
   for (int a=0; a<n; a++) {
     testPair.angleX = testAngles[a];
     
     for (int b=0; b<n; b++) {
       int positionNumber = (a*n) + b;  //  positionNumber increases by 1 from 1 to n^2 for every iteration of the double for loop.
       testPair.angleY = testAngles[b];
       if (servos_test_feedback) {
       Serial.print("a: "); Serial.println(a);
       Serial.print("b: "); Serial.println(b);
       Serial.print("positionNumber: "); Serial.println(positionNumber); }

       positionsArray[positionNumber] = testPair;  // Write the current testPair to the current positionsArray[] element.

       if (servos_test_feedback) {
         Serial.print(positionsArray[positionNumber].angleX); 
         Serial.print(", "); Serial.println(positionsArray[positionNumber].angleY);}
       //delay(20);
     }
   }
  Serial.println("");   
  
   delay(1000);

  /*----------------------------------------------------------------------------*/
   //Serial.print("freeMemory: "); Serial.println(freeMemory());

   int new_val = random(1,121);
   //int randomArray[n*n]; 
   if (servos_test_feedback) {Serial.println("randomArray[] Values:");}
   
   for (int i=0; i<n; i++) {
     new_val = random(1,n);
     for (int j=0; j<n; j++) {
       int positionNumber = (i*n) + j;   
       for (int k=0; k< positionNumber; k++) {
         if(new_val  == randomArray[k]) {
           new_val = random(1,n*n);
           k = 0;
         }
       }
       randomArray[positionNumber] = new_val;
       new_val = random(1,n*n);
       if (servos_test_feedback) {
         Serial.print("random array elements: "); Serial.print(positionNumber); 
         Serial.print("  value: "); Serial.println(randomArray[positionNumber]); }
     } 
   }
   
   delay(1000);
 
  /*----------------------------------------------------------------------------*/
  
  //AnglePair randomPositionsArray[n*n];
  if (servos_test_feedback) {
    Serial.println(""); 
    Serial.println("randomPositinsArray[] Values:");}
  
  for (i=0; i<n*n; i++) {
    randomPositionsArray[i] = positionsArray[randomArray[i]];
    if (servos_test_feedback) {
      Serial.print(randomPositionsArray[i].angleX); Serial.print(", "); Serial.println(randomPositionsArray[i].angleY);}
  }
 
 
// 
// 
//  Serial.println(""); Serial.println(""); Serial.println("");
//  //Serial.print("freeMemory: "); Serial.println(freeMemory());
//  delay(4000);
//  Serial.println("angleX, angleY");
//  Serial.println("feedbackX, feedbackY");
//  Serial.println(""); Serial.println(""); Serial.println("");
//  Serial.print("freeMemory: "); Serial.println(freeMemory());
//  
//  for(i=0; i<(n*n); i++) {
//    
//    //servo_x(randomPositionsArray[i].angleX);
//    //servo_y(randomPositionsArray[i].angleY);
//
//   Serial.print("freeMemory: "); Serial.println(freeMemory()); 
//    feedback1 = analogRead(feedbackPin1); 
//    feedback2 = analogRead(feedbackPin2);
//    
//    // These Serial.print instructions should be used to most clearly output data to the Serial.monitor.
//         // Serial.print(randomPositionsArray[i].angleX); 
//           
//        //  if (randomPositionsArray[i].angleX < 100) {Serial.print(" , "); }
//        //  else {Serial.print(", ");}
//          
//         // Serial.println(randomPositionsArray[i].angleY);
//          
//         // Serial.print(feedback1);  Serial.print(", "); Serial.println(feedback2); Serial.println("");
//          
//    // These Serial.print instrucitons should be used to transfer data to Excel for analysis.
//    //Serial.print((randomArray[i]+1)); 
//    //Serial.print(","); 
//    //Serial.print(feedback1); 
//    //Serial.print(","); 
//    //Serial.println(feedback2);
//  }
//  
 }
