#include <Arduino.h>
#include "protothreads.h"

unsigned int SleepTime_A = 0;
int SEC_A_PWM = 0;
int Wait_A = 0;

int RunSection_A(struct pt* pt) {

  PT_BEGIN(pt);
  for (;;) {
    Wait_A = random(WaitMin, WaitMax);// Needs to stay inside this scope

    SleepTime_A = Wait_A;
    SEC_A_PWM = LOW;
    if (SerialMonitor) {
      Serial.print("Section ");
      Serial.print (SEC_A);
      Serial.print(" waiting Low for: ");
      Serial.println(Wait_A);
    }
    analogWrite(SEC_A, SEC_A_PWM);
    PT_SLEEP(pt, SleepTime_A);

    RampLoopIndex = 0;
    SEC_A_PWM = 0;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_A = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_A_PWM = SEC_A_PWM + Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_A);
        Serial.print(" Ramp Up ");
        Serial.print(SleepTime_A);
        Serial.print("ms at ");
        Serial.print(SEC_A_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_A, SEC_A_PWM);
      PT_SLEEP(pt, SleepTime_A);
    }

    if (SerialMonitor) {
      Serial.print("Pin ");
      Serial.print (SEC_A);
      Serial.print(" Holding for ");
      Serial.print(Duration);
      Serial.print("ms at ");
      Serial.print(SEC_A_PWM );
      Serial.println(".");
    }
    analogWrite(SEC_A, SEC_A_PWM);
    PT_SLEEP(pt, Duration);


    RampLoopIndex = 0;
    SEC_A_PWM = PWM_HIGH;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_A = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_A_PWM = SEC_A_PWM - Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_A);
        Serial.print(" Ramp Down ");
        Serial.print(SleepTime_A);
        Serial.print("ms at ");
        Serial.print(SEC_A_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_A, SEC_A_PWM);
      PT_SLEEP(pt, SleepTime_A);
    }

  }
  PT_END(pt);
}
