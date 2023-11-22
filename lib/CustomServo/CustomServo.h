#ifndef CustomServo_h
#define CustomServo_h

//#include <Servo.h>

class CustomServo {
  public:
    CustomServo(int pin, float phaseshift, float amplitude);
    float update(unsigned long t);

  private:
    //Servo servo;
    float phaseshift; // 位相
    float amplitude; // 振幅
};

#endif