#include <math.h>
#include <Servo.h>

class CustomServo {
  private:
    //Servo servo; // Servo オブジェクト
    float phaseshift; // フェーズシフト
    float amplitude; // 振幅

  public:
    CustomServo(int pin, float phaseshift, float amplitude) {
      this->phaseshift = phaseshift;
      this->amplitude = amplitude;
      //this->servo.attach(pin);
    }

    float update(unsigned long t) {
      float angle = this->amplitude * sin(t / 1000.0 + this->phaseshift);
      //this->servo.write(angle * 180.0 / M_PI);
      return angle;
    }
};