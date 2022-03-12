
#include <Arduino.h>
#include <Servo.h>


#include <math.h>

// Linear interpolation (no easing)
float linear(float x);

// Quadratic easing; p^2
float easeInQuadratic(float x);
float easeOutQuadratic(float x);
float easeInOutQuadratic(float x);

// Cubic easing; p^3
float easeInCubic(float x);
float easeOutCubic(float x);
float easeInOutCubic(float x);

// Quartic easing; p^4
float easeInQuartic(float x);
float easeOutQuartic(float x);
float easeInOutQuartic(float x);

// Quintic easing; p^5
float easeInQuintic(float x);
float easeOutQuintic(float x);
float easeInOutQuintic(float x);

// Sine wave easing; sin(p * PI/2)
float easeInSine(float x);
float easeOutSine(float x);
float easeInOutSine(float x);

// Circular easing; sqrt(1 - p^2)
float easeInCircular(float x);
float easeOutCircular(float x);
float easeInOutCircular(float x);

// Exponential easing, base 2
float easeInExponential(float x);
float easeOutExponential(float x);
float easeInOutExponential(float x);

// Exponentially-damped sine wave easing
float easeInElastic(float x);
float easeOutElastic(float x);
float easeInOutElastic(float x);

// Overshooting cubic easing; 
float easeInBack(float x);
float easeOutBack(float x);
float easeInOutBack(float x);

// Exponentially-decaying bounce easing
float easeInBounce(float x);
float easeOutBounce(float x);
float easeInOutBounce(float x);


// Modeled after the line y = x
float linear(float x) {
  return x;
}

// Modeled after the parabola y = x^2
float easeInQuadratic(float x) {
  return pow(x, 2);
}

// Modeled after the parabola y = -x^2 + 2x
float easeOutQuadratic(float x) {
  return -(x * (x - 2));
}

// Modeled after the piecewise quadratic
// y = (1/2)((2x)^2)             ; [0, 0.5)
// y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1]
float easeInOutQuadratic(float x) {
  return (x < 0.5) ? (2 * pow(x, 2)) : ((-2 * pow(x, 2)) + (4 * x) - 1);
}

// Modeled after the cubic y = x^3
float easeInCubic(float x) {
  return pow(x, 3);
}

// Modeled after the cubic y = (x - 1)^3 + 1
float easeOutCubic(float x) {
  return pow(x - 1, 3) + 1;
}

// Modeled after the piecewise cubic
// y = (1/2)((2x)^3)       ; [0, 0.5)
// y = (1/2)((2x-2)^3 + 2) ; [0.5, 1]
float easeInOutCubic(float x) {
  return (x < 0.5) ? (4 * pow(x, 3)) : (0.5 * pow(((2 * x) - 2), 3) + 1);
}

// Modeled after the quartic x^4
float easeInQuartic(float x) {
  return pow(x, 4);
}

// Modeled after the quartic y = 1 - (x - 1)^4
float easeOutQuartic(float x) {
  return pow(x - 1, 3) * (1 - x) + 1;
}

// Modeled after the piecewise quartic
// y = (1/2)((2x)^4)        ; [0, 0.5)
// y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1]
float easeInOutQuartic(float x) {
  return (x < 0.5) ? (8 * pow(x, 4)) : (-8 * pow(x - 1, 4) + 1);
}

// Modeled after the quintic y = x^5
float easeInQuintic(float x) {
  return pow(x, 5);
}

// Modeled after the quintic y = (x - 1)^5 + 1
float easeOutQuintic(float x) {
  return pow(x - 1, 5) + 1;
}

// Modeled after the piecewise quintic
// y = (1/2)((2x)^5)       ; [0, 0.5)
// y = (1/2)((2x-2)^5 + 2) ; [0.5, 1]
float easeInOutQuintic(float x) {
  return (x < 0.5) ? (16 * pow(x, 5)) : (0.5 * pow((2 * x) - 2, 5) + 1);
}

// Modeled after quarter-cycle of sine wave
float easeInSine(float x) {
  return sin((x - 1) * M_PI_2) + 1;
}

// Modeled after quarter-cycle of sine wave (different phase)
float easeOutSine(float x) {
  return sin(x * M_PI_2);
}

// Modeled after half sine wave
float easeInOutSineEaseInOut(float x) {
  return 0.5 * (1 - cos(x * M_PI));
}

// Modeled after shifted quadrant IV of unit circle
float easeInCircular(float x) {
  return 1 - sqrt(1 - pow(x, 2));
}

// Modeled after shifted quadrant II of unit circle
float easeOutCircular(float x) {
  return sqrt((2 - x) * x);
}

// Modeled after the piecewise circular function
// y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5)
// y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1]
float easeInOutCircular(float x) {
  return (x < 0.5) ? (0.5 * (1 - sqrt(1 - 4 * pow(x, 2)))) : (0.5 * (sqrt(-((2 * x) - 3) * ((2 * x) - 1)) + 1));
}

// Modeled after the exponential function y = 2^(10(x - 1))
float easeInExponential(float x) {
  return (x == 0.0) ? x : pow(2, 10 * (x - 1));
}

// Modeled after the exponential function y = -2^(-10x) + 1
float easeOutExponential(float x) {
  return (x == 1.0) ? x : 1 - pow(2, -10 * x);
}

// Modeled after the piecewise exponential
// y = (1/2)2^(10(2x - 1))         ; [0,0.5)
// y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1]
float easeInOutExponential(float x) {
  if(x == 0.0 || x == 1.0) return x;
  
  return (x < 0.5) ? (0.5 * pow(2, (20 * x) - 10)) : (-0.5 * pow(2, (-20 * x) + 10) + 1);
}

// Modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1))
float easeInElastic(float x) {
  return sin(13 * M_PI_2 * x) * pow(2, 10 * (x - 1));
}

// Modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1
float easeOutElastic(float x) {
  return sin(-13 * M_PI_2 * (x + 1)) * pow(2, -10 * x) + 1;
}

// Modeled after the piecewise exponentially-damped sine wave:
// y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1))      ; [0,0.5)
// y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) ; [0.5, 1]
float easeInOutElastic(float x) {
  return (x < 0.5) ? 
    (0.5 * sin(13 * M_PI_2 * (2 * x)) * pow(2, 10 * ((2 * x) - 1)))
    : (0.5 * (sin(-13 * M_PI_2 * ((2 * x - 1) + 1)) * pow(2, -10 * (2 * x - 1)) + 2));
}

// Modeled after the overshooting cubic y = x^3-x*sin(x*pi)
float easeInBack(float x) {
  return pow(x, 3) - x * sin(x * M_PI);
}

// Modeled after overshooting cubic y = 1-((1-x)^3-(1-x)*sin((1-x)*pi))
float easeOutBack(float x) {
  return 1 - (pow(1 - x, 3) - (1 - x) * sin((1 - x) * M_PI));
}

// Modeled after the piecewise overshooting cubic function:
// y = (1/2)*((2x)^3-(2x)*sin(2*x*pi))           ; [0, 0.5)
// y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) ; [0.5, 1]
float easeInOutBack(float x) {
  return (x < 0.5) ? 
    (0.5 * (pow(2 * x, 3) - 2 * x * sin(2 * x * M_PI)))
    : (0.5 * (1 - (pow((1 - (2 * x - 1)), 3) - (1 - (2 * x - 1)) * sin((1 - (2 * x - 1)) * M_PI))) + 0.5);
}

float easeInBounce(float x) {
  return 1 - easeOutBounce(1 - x);
}

float easeOutBounce(float x) {
  if (x < 1 / 2.75) {
    return 7.5625 * pow(x, 2);
  }
  else if (x < 2 / 2.75) {
    return 7.5625 * pow(x - (1.5 / 2.75), 2) + 0.75;
  }
  else if (x < 2.5 / 2.75) {
    return 7.5625 * pow(x - (2.25 / 2.75), 2) + 0.9375;
  }
  else {
    return 7.5625 * pow(x - (2.625 / 2.75), 2) * x + 0.984375;
  }
}

float easeInOutBounce(float x) {
  return (x < 0.5) ? (0.5 * easeInBounce(x * 2)) : (0.5 * easeOutBounce(x * 2 - 1) + 0.5);
}

Servo servo_0;
Servo servo_1;

char state = '0';

void setup() {
  Serial.begin(115200);
  servo_0.attach(9);
  servo_1.attach(10);

//  Serial.println("ready");
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4') state = c;
  }

  for (float linear=0; linear<1; linear+=0.005) {
    
    switch (state) {
      case '0':
        servo_0.writeMicroseconds(1000 + (int)(linear * 1000));
        servo_1.writeMicroseconds(1000 + (int)(easeInOutCubic(linear) * 1000));
        break;
      case '1':
        servo_0.writeMicroseconds(1000 + (int)(easeInOutQuadratic(linear) * 1000));
        servo_1.writeMicroseconds(1000 + (int)(easeInOutCubic(linear) * 1000));
        break;
      case '2':
        servo_0.writeMicroseconds(1000 + (int)(easeInCubic(linear) * 1000));
        servo_1.writeMicroseconds(1000 + (int)(easeOutCubic(linear) * 1000));
        break;
      case '3':
        servo_0.writeMicroseconds(1000 + (int)(easeOutBack(linear) * 1000));
        servo_1.writeMicroseconds(1000 + (int)(easeInOutBack(linear) * 1000));
        break;
      case '4':
        servo_0.writeMicroseconds(1000 + (int)(easeOutElastic(linear) * 1000));
        servo_1.writeMicroseconds(1000 + (int)(easeOutBounce(linear) * 1000));
        delay(10);
        break;
    }
    Serial.print(state);
    Serial.print("\t");
    Serial.print(linear);
    Serial.print("\t");
    Serial.println(easeOutBounce(linear));
    
    delay(5);
  }
  delay(500);
  
  for (float linear=0; linear<1; linear+=0.005) {

    switch (state) {
      case '0':
        servo_0.writeMicroseconds(2000 - (int)(linear * 1000));
        servo_1.writeMicroseconds(2000 - (int)(easeInOutCubic(linear) * 1000));
        break;
      case '1':
        servo_0.writeMicroseconds(2000 - (int)(easeInOutQuadratic(linear) * 1000));
        servo_1.writeMicroseconds(2000 - (int)(easeInOutCubic(linear) * 1000));
        break;
      case '2':
        servo_0.writeMicroseconds(2000 - (int)(easeInCubic(linear) * 1000));
        servo_1.writeMicroseconds(2000 - (int)(easeOutCubic(linear) * 1000));
        break;
      case '3':
        servo_0.writeMicroseconds(2000 - (int)(easeOutBack(linear) * 1000));
        servo_1.writeMicroseconds(2000 - (int)(easeInOutBack(linear) * 1000));
        break;
      case '4':
        servo_0.writeMicroseconds(2000 - (int)(easeOutElastic(linear) * 1000));
        servo_1.writeMicroseconds(2000 - (int)(easeOutBounce(linear) * 1000));
        delay(10);
        break;
    }
    Serial.print(state);
    Serial.print("\t");
    Serial.print(linear);
    Serial.print("\t");
    Serial.println(easeOutBounce(linear));
    
    delay(5);
  }
  delay(500);
  
}
