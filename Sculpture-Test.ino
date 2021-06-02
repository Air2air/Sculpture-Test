// #include <Arduino.h>
#include <pt.h>

int Section = 0;
//unsigned long Duration = 8000;


bool Print_Serial = 1;

/* Master PWM */
int PWM_HIGH = 50;
int PWM_LOW = 0;

int Wait_A = 0;
int Wait_B = 0;
int Wait_C = 0;
int Wait_D = 0;

const int WaitMin = 3000;
const int WaitMax = 6000;

unsigned int NumRampLoops = 5;
const int Ramp_PWM_Increment = PWM_HIGH / NumRampLoops;

/* Ramp */
unsigned long Ramp_Time_Increment = 120;


/* _A_ */
float _A_Bias = .6;


/* _B_ */
float _B_Bias = .8;


/* _C_ */
float _C_Bias = .8;


/* _D_ */
float _D_Bias = 1.2;
