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

byte IR0=0;
byte IR1=1;
byte IR2=2;

int maxVal0=0;
int maxVal1=0;
int maxVal2=0;

int minVal0=1024; 
int minVal1=1024;
int minVal2=1024;

int latestVal0=0;
int latestVal1=0;
int latestVal2=0;


///Serial stuff

int input = 0;
int j=0; //temp int for looping through and stopping test step run

int currentMasterIndex;
int inByte;


void setup(){
  Serial.begin(9600);

  for (int i=0; i< arraySize; i ++){
    stepperMotors[i].setMaxSpeed(1000);
    stepperMotors[i].setSpeed(2000);
  }

  CalibrateIR();
  CalibrateMotors();

}

void loop(){
  Serial.println(j);
  //hannah look at logic here!!! later where do the if statements live etc.
  if(input == 1){
    checkSerial();
    stepperMotors[currentMasterIndex].runSpeed();
    j++;       
  }
  delay(1);
}

void serialEvent(){
  while (Serial.available()){
    inByte= Serial.read();
    ///finish up the handshaking
    input = 1;
    switch (inByte){
    case '1':
      currentMasterIndex=0;
      break;
    case '2':
      currentMasterIndex= 1;
      break;
    case '3': 
      currentMasterIndex = 2;
    } 
    Serial.println("currentMasterIndex");
    Serial.println( currentMasterIndex);
    delay (30);
  }
}

void checkSerial(){
  if (inByte != currentMasterIndex){
    stepperMotors[currentMasterIndex].stop();
    Serial.println("stop motors new master recieved");
  }
  if (j> 300){
    stepperMotors[currentMasterIndex].stop();
    input = 0; 
    j=0;
    Serial.println("stop motors end of cycle");
  }
}



