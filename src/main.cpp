#include <Arduino.h>
#include <math.h>
#include <Servo.h>

#define NUM_SERVOS 8

struct ServoState {
  float phaseshift; // 位相
  float offset; // 振動の中心
  float amplitude; // 振幅
  float speed; // 回転速度
};
class Servo_ {
  private:
    int pin;
    Servo servo;
    ServoState state;

  public:
    Servo_(int pin, ServoState& state) : pin(pin), state(state){
      // init();
    }

    void init(){
      servo.attach(pin);
    }

    float update(unsigned long t) {
      float rad = state.phaseshift * M_PI / 180.0;
      float angle = state.amplitude * sin(state.speed * t / 1000.0 + rad);
      servo.write(angle + state.offset);
      return angle;
    }
};


/*
servo positions
    ----
2 1 |  | 5 6 
    |  |
4 3 |  | 7 8
    ----
*/
ServoState states[NUM_SERVOS] = {
  {0, 90, 40, 2},
  {0, 60, 15, 2},
  {0, 90, 40, -2},
  {0, 120, 15, -2},
  {0, 90, 40, 2},
  {0, 120, 15, 2},
  {0, 90, 40, -2},
  {0, 120, 15, -2}
};
Servo_ servos[NUM_SERVOS]{
  Servo_(2, states[0]),
  Servo_(3, states[1]),
  Servo_(4, states[2]),
  Servo_(5, states[3]),
  Servo_(6, states[4]),
  Servo_(7, states[5]),
  Servo_(8, states[6]),
  Servo_(9, states[7])
};

void setup() {
  Serial.begin(115200);
  for(int i=0; i<NUM_SERVOS; i++){
    servos[i].init();
  }
}

void loop() {
  unsigned long t = millis();
  for(int i=0; i<NUM_SERVOS; i++){
    servos[i].update(t);
  }
  delay(20);
}
