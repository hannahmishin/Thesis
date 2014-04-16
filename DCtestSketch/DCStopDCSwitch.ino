void RunTLDC(){
  if (TLone == 1){
    TLleft();
  }
  else{
    TLright();
  }
  ChangeDirTL(); 
}



void ChangeDirTL(){
  TLstate = digitalRead(TLswitch);

  boolean  switchHitTL = false;
  int ignoreTLSwitchUntil = 0;

  if (TLstate == HIGH) {      
    switchHitTL = true;
    ignoreTLSwitchUntil = millis();
    digitalWrite (TL1, LOW);
    digitalWrite (TL2, LOW);
  }


  if (TLone == 1 && switchHitTL == true && (millis() - waitTime < ignoreTLSwitchUntil)){
    TLright();
    switchHitTL = false;
    Serial.println("TLRIGHT");
  }

  if (TLone == 0 && switchHitTL == true && (millis() - waitTime < ignoreTLSwitchUntil)){
    TLleft(); 
    switchHitTL = false; 
    Serial.println("TLLEFT");
  }

}






