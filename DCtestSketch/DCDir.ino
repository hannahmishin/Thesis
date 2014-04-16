void TRright(){
  digitalWrite(TR1, HIGH);  
  digitalWrite(TR2, LOW);  
}

void TRleft(){
  digitalWrite(TR1, LOW);  
  digitalWrite(TR2, HIGH);  
}


///TOP LEFT DC


void TLleft(){
  digitalWrite(TL1, HIGH);  
  digitalWrite(TL2, LOW);   
  TLone = 1;
  TLtwo = 0;
  
}


void TLright(){
  digitalWrite(TL1, LOW);  
  digitalWrite(TL2, HIGH); 
TLtwo = 1;
TLone = 0;
}




void BRleft(){
    digitalWrite(BR1, HIGH);  
  digitalWrite(BR2, LOW);   
}
void BRright(){
    digitalWrite(BR1, LOW);  
  digitalWrite(BR2, HIGH);   
}


void BLright(){
  digitalWrite(BL1, HIGH);  
  digitalWrite(BL2, LOW);  
}

void BLleft(){
  digitalWrite(BL1, LOW);  
  digitalWrite(BL2, HIGH);  
}
