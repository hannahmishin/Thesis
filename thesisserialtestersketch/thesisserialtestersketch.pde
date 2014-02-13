import processing.serial.*;
Serial Port;  
byte MasterDefined;

void setup () {
  size(800, 600);       

  // should be 0
  println(Serial.list());
  String USB = Serial.list()[0];
 Port = new Serial(this, USB, 9600);
}
void draw () {
 
  if( keyPressed) {
    if (key == '1'){
      MasterDefined = 1;
    }
    if (key == '2'){
      MasterDefined = 2;
    }
    
    if (key == 3){
      MasterDefined =3;
    }
     
    Port.write(MasterDefined); 
    println(MasterDefined);

     }
  }

