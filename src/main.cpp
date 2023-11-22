#include <Arduino.h>
#include <math.h>
#include <Servo.h>

class CustomServo {
  private:
    Servo servo;
    float phaseshift; // フェーズシフト
    float amplitude; // 振幅

  public:
    CustomServo(float phaseshift, float amplitude) {
      this->phaseshift = phaseshift;
      this->amplitude = amplitude;
    }
    void attach(int pin){
      servo.attach(pin);
    }

    float update(unsigned long t) {
      float angle = amplitude * sin(t / 1000.0 + phaseshift);
      servo.write(angle + 90);
      return angle;
    }
};

CustomServo servo1(0, 60);
CustomServo servo2(0, 30);

void setup() {
  Serial.begin(115200);
  servo1.attach(A0);
  servo2.attach(A1);
  /*
  for( int i=0; i<NUM_SERVOS; i++){
    myServo[i].attach( A0 + i );      // pin A0,A1...
    myServo[i].update(0);
    delay(10);
  }
  */
}

void loop() {
  //for( int i=0; i<NUM_SERVOS; i++){
    unsigned long t = millis();
    float angle = servo1.update(t);
    servo2.update(t);
    Serial.println(angle);
    delay(200);
  //}
}
