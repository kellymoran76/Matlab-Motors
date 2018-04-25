#include <LibraryBase.h>
#include <AFMotor.h>
#include <AccelStepper.h>
#include <Servo.h>
#include <string.h>

int xposition;
int yposition;

AF_Stepper motor1(200,1);
AF_Stepper motor2(200,2);
Servo servo1;

void forwardstep1() {
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {
  motor1.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {
  motor2.onestep(BACKWARD, SINGLE);
}

AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);


class motor : public LibraryBase
{

private:
  //AccelStepper stepper1(forwardstep1, backwardstep1);
  //AccelStepper stepper2(forwardstep2, backwardstep2);
    public:
        motor(MWArduinoClass& a)
        {
            libName = "MotorAddon/motor";
            a.registerLibrary(this);
        }

        void setup()
        {
            stepper1.setMaxSpeed(200.0);
            stepper1.setAcceleration(100.0);
            stepper1.moveTo(20000);
            stepper1.run();

            stepper2.setMaxSpeed(300.0);
            stepper2.setAcceleration(100.0);
            stepper2.moveTo(2000);
            stepper2.run();
            servo1.attach(9);
            servo1.write(90);
        }
  void loop()
        {
            stepper1.run();
            stepper2.run();
        }
	void commandHandler(byte cmdID, byte* dataIn, unsigned int payloadSize)
    {
        switch(cmdID)
        {
            case 0x01:
            {
              byte yposition = dataIn[0];
              stepper1.moveTo(yposition);
              stepper1.run();
              byte result [200] = {1};
              sendResponseMsg(cmdID, result, 200);
              break;
            }
            case 0x02:
            {
              byte xposition = dataIn[0];
              stepper2.moveTo(xposition);
              stepper2.run();
              byte result [200] = {1};
              sendResponseMsg(cmdID, result, 200);
              break;
            }
            case 0x03:
            {
              byte position = dataIn[0];
              servo1.write(position);
              byte result [200] = {1};
              sendResponseMsg(cmdID,result,200);
              break;
            }
            default:
            {
                break;// Do nothing
            }
        }
    }
};
