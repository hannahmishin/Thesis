void CalibrateMotors(){
  int IRThreshold0 = maxVal0;
  int IRThreshold1 = maxVal1;
  int IRThreshold2 = maxVal2;
  
  latestVal0 = analogRead(IR0);
  latestVal1 = analogRead(IR1);
  latestVal2 = analogRead(IR2);

  if(latestVal0 != IRThreshold0){ 
    stepperMotors[0].run();
    Serial.println("calibrate 0 motor");
  }
  if (latestVal0 > IRThreshold0){
    Serial.println("TRUE 0");
    stepperMotors[0].stop();
  }

  stepperMotors[1].run(); 

  if (latestVal1 > IRThreshold1){
    Serial.println("TRUE 1");
    stepperMotors[1].stop();
  } 

  stepperMotors[2].run(); 

  if (latestVal2 > IRThreshold2){
    Serial.println("TRUE 2");
    stepperMotors[2].stop();
  } 


}


