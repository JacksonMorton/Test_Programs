

 void servos_test() {
  
  servo_x(90); servo_y(90);
   
  build_positionsArray();
  
  Serial.println(""); Serial.println(""); Serial.println("");
  delay(2000);
  Serial.println("angleX, angleY");
  Serial.println("feedbackX, feedbackY");
  Serial.println(""); Serial.println(""); Serial.println("");
  
  for(i=0; i<n*n; i++) {
    
    servo_x(randomPositionsArray[i].angleX);
    servo_y(randomPositionsArray[i].angleY);
    
    delay(2000);
    //int time = millis();
    //while(millis() <+ time + 2000) {Serial.println("Waiting...");};
    
    feedback1 = analogRead(feedbackPin1); 
    feedback2 = analogRead(feedbackPin2);
    
    // These Serial.print instructions should be used to most clearly output data to the Serial.monitor.
          //Serial.print(randomPositionsArray[i].angleX); 
          // 
          //if (randomPositionsArray[i].angleX < 100) {Serial.print(" , "); }
          //else {Serial.print(", ");}
          //
          // Serial.println(randomPositionsArray[i].angleY);
          //
          //Serial.print(feedback1);  Serial.print(", "); Serial.println(feedback2); Serial.println("");
          
    // These Serial.print instrucitons should be used to transfer data to Excel for analysis.
    Serial.print((randomArray[i]+1)); 
    Serial.print(","); 
    Serial.print(feedback1); 
    Serial.print(","); 
    Serial.println(feedback2);
  }
  
  delay(5000);
  
 }
