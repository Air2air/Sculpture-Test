

/* Pins */
const int SEC_A = 3;
const int SEC_B = 5;
const int SEC_C = 6;
const int SEC_D = 9;

bool SerialMonitor = 1;
bool SerialRamp = 1;

/* Master PWM */
int PWM_HIGH = 36;
int PWM_LOW = 0;

/* Hold time */
int Duration = 6000;

/* Random Delay */
const int WaitMin = 10000;
const int WaitMax = 20000;

/* Ramp */
unsigned int Ramp_Time_Increment = 60;
unsigned int NumRampLoops = 12;
unsigned int RampLoopIndex = 0;
const int Ramp_PWM_Increment = PWM_HIGH / NumRampLoops;

/* Bias */
float Bias_A = .6;
float Bias_B = .8;
float Bias_C = .8;
float Bias_D = 1.2;
