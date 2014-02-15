import processing.serial.*;
Serial Port;  
byte MasterDefined;
byte newVal;

void setup () {
  size(800, 600);       

  // should be 0
  println(Serial.list());
  String USB = Serial.list()[0];
  Port = new Serial(this, USB, 9600);
}
void draw () {

  if ( keyPressed) {
  
    if (key == '1') {
      newVal = 0;
    }
    if (key == '2') {
      newVal = 2;
    }
    if (key == '3') {
      newVal =3;
    }
    if (newVal!=MasterDefined) {
      MasterDefined = newVal;
      Port.write(MasterDefined); 
     // println(MasterDefined);
    }
  }
}


//  if last valuem dont send
//  change last value to current value
//  
//  int last value 

