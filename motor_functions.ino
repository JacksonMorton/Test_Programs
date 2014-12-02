  
  
  void toggleSwitch(int motor) {
    
    for(i=0; i < (sizeof(testValues)/sizeof(int)); i++) {
      //Serial.print("lastMode: "); Serial.print(lastMode); Serial.print("   manual: "); Serial.print(manual);
      manual = digitalRead(mode_switch);
      feedback_on = true;
      
      while (lastMode == manual) {
        //Serial.println("manual: "); Serial.println(manual);
        if (motor == x) {
          servo1.write(u);
          servo2.write(90); 
          z = x;}
        else if (motor == y) {
          servo1.write(90);
          servo2.write(u);
          z = y; }
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
  

  
  void feedback() {
    feedback1 = analogRead(feedbackPin1); feedback2 = analogRead(feedbackPin2);
    feedback1_map = map(feedback1, 259, 356, 45, 135); feedback2_map = map(feedback2, 245, 340, 45, 135);
    Serial.println("");
    if (z == x) {
    Serial.print("servo1 feedback: "); Serial.print(feedback1); Serial.println(" (This number is between 259 and 356.)");
    Serial.print("servo1 mapped feedback: "); Serial.print(feedback1_map); Serial.println(" degrees"); }
    else if (z == y) {
    Serial.print("servo2 feedback: "); Serial.print(feedback2); Serial.println(" (This number is between 245 and 340.)");
    Serial.print("servo2 mapped feedback: "); Serial.print(feedback2_map); Serial.println(" degrees"); }
    Serial.println(""); Serial.println(""); 
    feedback_on = false;
  }
  
  /**************************************************************************/
  
  void center() {
 
  servo1.write(90);
  servo2.write(90);
  
  feedback1 = analogRead(feedbackPin1); feedback2 = analogRead(feedbackPin2);
  feedback1_map = map(feedback1, 259, 356, 45, 135); feedback2_map = map(feedback2, 245, 340, 45, 135);
  Serial.println("");
  Serial.print("servo1 feedback: "); Serial.print(feedback1); Serial.println(" (This number is between 259 and 356.)");
  Serial.print("servo1 mapped feedback: "); Serial.print(feedback1_map); Serial.println(" degrees"); 
  Serial.print("servo2 feedback: "); Serial.print(feedback2); Serial.println(" (This number is between 245 and 340.)");
  Serial.print("servo2 mapped feedback: "); Serial.print(feedback2_map); Serial.println(" degrees"); 
  Serial.println(""); Serial.println(""); 
 
  delay(3000);
 
  }
