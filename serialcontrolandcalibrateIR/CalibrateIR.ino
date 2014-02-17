void CalibrateIR(){

  for (int j = 0; j < 400; j++)  // make the calibration take about 10 seconds
  {
    stepperMotors[0].runSpeed();
    Serial.println("STEPPER 0");
    latestVal0 = analogRead(IR0);

    if(latestVal0 < minVal0) {
      minVal0 = latestVal0; 
    }
    if(latestVal0 > maxVal0) {
      maxVal0 = latestVal0; 

    }
  }
  stepperMotors[0].stop();

  for (int j = 0; j < 400; j++)  // make the calibration take about 10 seconds
  {
    stepperMotors[1].runSpeed();
    Serial.println("STEPPER 1");
    latestVal1 = analogRead(IR1);
    if(latestVal1 < minVal1) {
      minVal1 = latestVal1; 
    }
    if(latestVal1 > maxVal1) {
      maxVal1 = latestVal1;  
    }
  }
  stepperMotors[1].stop();

  for (int j = 0; j < 400; j++)  // make the calibration take about 10 seconds
  {
    stepperMotors[2].runSpeed();
     Serial.println("STEPPER 2");
    
    latestVal2 = analogRead(IR2);
    if(latestVal2 < minVal2) {
      minVal2 = latestVal2; 
    }
    if(latestVal2 > maxVal2) {
      maxVal2 = latestVal2;  
    }
  }
  stepperMotors[2].stop();

  Serial.println("CALIBRATED");
}









