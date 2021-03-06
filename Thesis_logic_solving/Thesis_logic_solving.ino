#include <AccelStepper.h>
#include <QTRSensors.h>


///stepper arrays and related stepper stuff

AccelStepper steppers0(AccelStepper::FULL4WIRE, 2, 3, 4, 5);
AccelStepper steppers1(AccelStepper::FULL4WIRE, 6, 7, 8, 9);
AccelStepper steppers2(AccelStepper::FULL4WIRE, 10, 11, 12, 13);

///arraySize should match at all times the actual amount of the stepperMotor array
int arraySize = 3;
AccelStepper stepperMotors[3]= {steppers0, steppers1, steppers2};


//IR STUFF

#define NUM_SENSORS             3  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  3  // average 4 analog samples per sensor reading
QTRSensorsAnalog qtra((unsigned char[]) {
  0}
, 
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);

unsigned int sensorValues[NUM_SENSORS];

unsigned int IRValue[0];

int IRthreshold = 800;

///set logic stuff for master slave stepper stuff

boolean input;

int currentMasterIndex = 0;


void setup(){
  Serial.begin(9600);
    for (int i=0; i< arraySize; i ++){
  stepperMotors[i].setMaxSpeed(1000);
  stepperMotors[i].setSpeed(50);
  }



}

void loop(){
  //hannah look at logic here!!! later where do the if statements live etc.
  if(currentMasterIndex>0 && input == true){
  //  for(int i=0; i< arraySize; i++){
       stepperMotors[1].runSpeed();
        delay (10);
        stepperMotors[2].runSpeed();   
    }
     // if(i == currentMasterIndex){
       // do master behaviour for this index
        //
      }
//      else{
//        //this index is not a master so execute slave behaviour
// input = false;
//      }
      //else{
     //   for(int i=0; i< arraySize; i++){
          //no people so all steppers set to neutral
          
      //  }
  //  }
//  }

//}
void serialEvent(){
  while (Serial.available()){
    currentMasterIndex = Serial.read();
    ///finish up the handshaking
    input = true;
    delay (10);
    Serial.print(input);
}
    //Clear current stepper behavious
  }
//}








