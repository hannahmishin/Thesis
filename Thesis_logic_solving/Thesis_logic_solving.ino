#include <Stepper.h>
#include <QTRSensors.h>


///stepper arrays and related stepper stuff
const int stepsofstepper = 512;

int stepCount= 0;

Stepper steppers0(stepsofstepper, 2, 3, 4, 5);
Stepper steppers1(stepsofstepper, 6, 7, 8, 9);
Stepper steppers2(stepsofstepper, 10, 11, 12, 13);

Stepper StepperMotors[3]= {steppers0, steppers1, steppers2};



//IR STUFF

#define NUM_SENSORS             3  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  3  // average 4 analog samples per sensor reading
QTRSensorsAnalog qtra((unsigned char[]) {0}, 
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);

unsigned int sensorValues[NUM_SENSORS];

unsigned int IRValue[0];
 
int IRthreshold = 800;

///set logic stuff for master slave stepper stuff
boolean Master = false;

byte MasterDefined;

void setup(){
  Serial.begin(9600);

}

void loop(){
  if (Master == false);
  ///execute neutral behavior movement
  if (Master == true);
  ///set all steppers to slave stepper array here
 Stepper Slaves[3]= StepperMotors[3];
 
 ///does not work. 
 Stepper Slaves[MasterDefined] = Stepper MasterStepper;
  
}

void serialEvent(){
  while (Serial.available()){
    MasterDefined = (byte)Serial.read();
  ///finish up the handshaking
  
  }
}
    





