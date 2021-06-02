



int Section = 0;
//unsigned long Duration = 8000;

const int SEC_A = 11;
const int SEC_B = 10;
const int SEC_C = 9;
const int SEC_D = 6;

bool Print_Serial = 1;



int SEC_A_PWM = 0;

int Duration = 1000;

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
unsigned int RampLoopIndex = 0;
const int Ramp_PWM_Increment = PWM_HIGH / NumRampLoops;

/* Ramp */
unsigned long Ramp_Time_Increment = 60;


/* _A */
float _ABias = .6;


/* _B */
float _BBias = .8;


/* _C */
float _CBias = .8;


/* _D */
float _DBias = 1.2;
