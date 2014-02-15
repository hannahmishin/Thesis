
#include <AccelStepper.h>
#include <QTRSensors.h>


///stepper arrays and related stepper stuff

AccelStepper steppers0(AccelStepper::FULL4WIRE, 2, 3, 4, 5);
AccelStepper steppers1(AccelStepper::FULL4WIRE, 6, 7, 8, 9);
AccelStepper steppers2(AccelStepper::FULL4WIRE, 10, 11, 12, 13);

///arraySize should match at all times the actual amount of the stepperMotor array
int arraySize = 3;
AccelStepper stepperMotors[3]= {
  steppers0, steppers1, steppers2};


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

int input = 0;
int j=0; //temp int for looping through and stopping test step run
int futureMasterIndex;
int currentMasterIndex;
int inByte;


void setup(){
  Serial.begin(9600);
  for (int i=0; i< arraySize; i ++){
    stepperMotors[i].setMaxSpeed(1000);
    stepperMotors[i].setSpeed(1000);
  }

}

void loop(){
  Serial.println(futureMasterIndex);

  //hannah look at logic here!!! later where do the if statements live etc.
  if(input == 1){
    stepperMotors[currentMasterIndex].stop();
    if(j < 350){
      //Serial.print("currentMasterIndex + ");
      //Serial.println( currentMasterIndex);
      stepperMotors[currentMasterIndex].runSpeed();

      j++;
      if (j > 349){
        input = 0; 
        j=0;      
        //        Serial.println("stop motors");
      }   
    }
    delay(1); 
  }

}

void serialEvent(){
  while (Serial.available()){
    inByte= (int)Serial.read();
    if(inByte == '\n' || inByte == '\r'){
      continue;
    }
    inByte -= '0';
    input = 1;
    //    Serial.println( inByte);
    switch (inByte){
    case 1:
      currentMasterIndex=0;
      break;
    case 2:
      currentMasterIndex= 1;
      break;
    case 3: 
      currentMasterIndex = 2;
      break;

    default: 
      break;
    }

  }
}









