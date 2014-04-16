
///limit switch timers
int waitTime = 10;
unsigned long time;


////DC MOTOR ////////////////
/////////////////////////////


//Top Left DC
const int TL1 = 2;  
int TLone;
const int TL2 = 3;
int TLtwo;
const int TLswitch = 14;
int TLstate = 0;

//Bottom Left DC
const int BL1 = 4;   
const int BL2 = 5; 
const int BLswitch = 15;
int BLstate = 0;



// Top Right DC
const int TR1 = 8;    
const int TR2 = 9;   
const int TRswitch = 17;
int TRstate = 0;


//Bottom Right DC
const int BR1 = 11;   
const int BR2 = 10;  
const int BRswitch = 18;
int BRstate = 0;


///STEPPER SHIT////
////////////////////
#define DIR_PIN 0
#define STEP_PIN 1

///my RX and TX... I need pins! can I make my switches analog YES





void setup() {
  
  
Serial.begin (9600);

  ////stepper MOTOR///
  pinMode(DIR_PIN, OUTPUT); 
  pinMode(STEP_PIN, OUTPUT); 

  ////DC MOTOR ////////////////
  /////////////////////////////

  //Top Left DC
  pinMode(TL1, OUTPUT); 
  pinMode(TL2, OUTPUT);
  pinMode(TLswitch, INPUT);


  //Bottom Left DC
  pinMode(BL1, OUTPUT); 
  pinMode(BL2, OUTPUT);
  pinMode(BLswitch, INPUT); 

  // Top Right DC
  pinMode(TR1, OUTPUT); 
  pinMode(TR2, OUTPUT);
  pinMode(TRswitch, INPUT);  

  //Bottom Right DC
  pinMode(BR1, OUTPUT); 
  pinMode(BR2, OUTPUT);
  pinMode(BRswitch, INPUT); 

}

void loop() {
    // LimitSwitches DC:
  TLstate = digitalRead(TLswitch);
  TRstate = digitalRead(TRswitch);
  BRstate = digitalRead(BRswitch);
  BLstate = digitalRead(BLswitch);
  
RunTLDC();
 

Serial.println(TLone);

}




