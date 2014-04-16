void testDCMotors(){  
  ////DC MOTOR ////////////////
/////////////////////////////


  ///Top Right DC
  digitalWrite(TR1, HIGH);  
  digitalWrite(TR2, LOW);   

  delay(1000);
  digitalWrite(TR1, LOW);  
  digitalWrite(TR2, LOW);
  delay(1000);

  digitalWrite(TR1, LOW);  
  digitalWrite(TR2, HIGH); 
  delay(1000);

  digitalWrite(TR1, LOW);  
  digitalWrite(TR2, LOW);
  delay(1000);



  ///Top Left DC
  digitalWrite(TL1, HIGH);  
  digitalWrite(TL2, LOW);   

  delay(1000);
  digitalWrite(TL1, LOW);  
  digitalWrite(TL2, LOW);
  delay(1000);

  digitalWrite(TL1, LOW);  
  digitalWrite(TL2, HIGH); 
  delay(1000);

  digitalWrite(TL1, LOW);  
  digitalWrite(TL2, LOW);
  delay(1000);

  //Bottom Right DC

  digitalWrite(BR1, HIGH);  
  digitalWrite(BR2, LOW);   

  delay(1000);
  digitalWrite(BR1, LOW);  
  digitalWrite(BR2, LOW);
  delay(1000);

  digitalWrite(BR1, LOW);  
  digitalWrite(BR2, HIGH); 
  delay(1000);

  digitalWrite(BR1, LOW);  
  digitalWrite(BR2, LOW);
  delay(1000);

  ///Bottom Left DC
  digitalWrite(BL1, HIGH);  
  digitalWrite(BL2, LOW);   

  delay(1000);
  digitalWrite(BL1, LOW);  
  digitalWrite(BL2, LOW);
  delay(1000);

  digitalWrite(BL1, LOW);  
  digitalWrite(BL2, HIGH); 
  delay(1000);

  digitalWrite(BL1, LOW);  
  digitalWrite(BL2, LOW);
  delay(1000);
  
}

