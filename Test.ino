// #include <Arduino.h>
#include <pt.h>

int SEC_A = 11;
int SEC_B = 10;
int SEC_C = 9;
int SEC_D = 6;

int Section = 0;
unsigned long Wait = 0;
unsigned long Duration = 4000;

bool Print_Serial = 1;

/* Master PWM */
int PWM_HIGH = 28;
int PWM_LOW = 0;

/* Outer Loop */
unsigned long Run_Duration = 10000;

/* Ramp */
unsigned long Ramp_Time_Increment = 70;
unsigned long Ramp_PWM_Increment = 3;

/* _A_ */
float _A_Bias = .6;
unsigned long SEC_A_WAIT = 100;
unsigned long SEC_A_DURATION = 4000;

/* _B_ */
float _B_Bias = .8;
unsigned long SEC_B_WAIT = 100;
unsigned long SEC_B_DURATION = 4000;

/* _C_ */
float _C_Bias = .8;
unsigned long SEC_C_WAIT = 1000;
unsigned long SEC_C_DURATION = 4000;

/* _D_ */
float _D_Bias = 1.2;
unsigned long SEC_D_WAIT = 100;
unsigned long SEC_D_DURATION = 1000;


static struct pt pt1, pt2, pt3, pt4;

void setup() {
  pinMode(SEC_A, OUTPUT);
  pinMode(SEC_B, OUTPUT);
  pinMode(SEC_C, OUTPUT);
  pinMode(SEC_D, OUTPUT);

  PT_INIT(&pt1);
  PT_INIT(&pt2);
  PT_INIT(&pt3);
  PT_INIT(&pt4);

  Serial.begin(115200);
  while (! Serial);



  analogWrite(SEC_A, 0);
  analogWrite(SEC_B, 0);
  analogWrite(SEC_C, 0);
  analogWrite(SEC_D, 0);
}
