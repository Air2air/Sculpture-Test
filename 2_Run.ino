
#include "protothreads.h"
#include <Arduino.h>


const int SEC_A = 11;
const int SEC_B = 10;
const int SEC_C = 9;
const int SEC_D = 6;



unsigned long This_PWM;
unsigned long Start_Time_Marker;

int RampUp_A(struct pt* pt) {

//  PT_BEGIN(pt);
//  for (;;) {

    unsigned long currentTime = millis();
    unsigned long Start_Time_Marker_A = currentTime;
    unsigned long Next_Ramp_Time_A;
    unsigned long WaitToRampUp_A;
    unsigned long This_PWM_A = 0 + Ramp_PWM_Increment;

    // Different for this first one
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker_A >= WaitToRampUp_A);
    This_PWM_A = PWM_LOW + Ramp_PWM_Increment;
    Next_Ramp_Time_A = (Start_Time_Marker_A + Ramp_Time_Increment);
    analogWrite(SEC_A, This_PWM_A);

    Serial.print("Ramp 1, Section A pin ");
    Serial.print(SEC_A);
    Serial.print(", Millis: ");
    Serial.print(millis() );
    Serial.print(", Next_Ramp_Time_A: ");
    Serial.print(Next_Ramp_Time_A);
    Serial.print(", This_PWM_A: ");
    Serial.println(This_PWM_A);

    PT_WAIT_UNTIL(pt, (millis() - Next_Ramp_Time_A) >= Next_Ramp_Time_A);
    This_PWM_A = This_PWM_A + Ramp_PWM_Increment;
    Next_Ramp_Time_A = (Next_Ramp_Time_A + Ramp_Time_Increment);
    analogWrite(SEC_A, This_PWM_A);

    Serial.print("Ramp 2, Section A pin ");
    Serial.print(SEC_A);
    Serial.print(", Millis: ");
    Serial.print(millis() );
    Serial.print(", Next_Ramp_Time_A: ");
    Serial.print(Next_Ramp_Time_A);
    Serial.print(", This_PWM_A: ");
    Serial.println(This_PWM_A);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker_A >= Next_Ramp_Time_A);
    This_PWM_A = This_PWM_A + Ramp_PWM_Increment;
    Next_Ramp_Time_A = (Next_Ramp_Time_A + Ramp_Time_Increment);
    analogWrite(SEC_A, This_PWM_A);

    Serial.print("Ramp 3, Section A pin ");
    Serial.print(SEC_A);
    Serial.print(", Millis: ");
    Serial.print(millis() );
    Serial.print(", Next_Ramp_Time_A: ");
    Serial.print(Next_Ramp_Time_A);
    Serial.print(", This_PWM_A: ");
    Serial.println(This_PWM_A);
//  }
//  PT_END(pt);
}




//
//static int Run(struct pt * pt, int Section, int Wait) {
//
//  unsigned long Start_Time_Marker;
//  unsigned long WaitToRampUp = Wait;
//  unsigned long StartRampDown = Wait + Duration;
//  unsigned long This_PWM;
//  unsigned long Next_Ramp_Time;
//
//  PT_BEGIN(pt);
//  while (1) {
//
//    Start_Time_Marker = millis();
//
//    //Start
//    if (Print_Serial) {
//      Serial_Start(Section, Wait);
//    }
//
//    Serial.print("Start_Time_Marker: ");
//    Serial.println(Start_Time_Marker);
//    Serial.print("WaitToRampUp: ");
//    Serial.println(WaitToRampUp);
//    Serial.print("StartRampDown: ");
//    Serial.println(StartRampDown);
//    Serial.print("Next_Ramp_Time: ");
//    Serial.println(Next_Ramp_Time);
//
//
//    // Ramp Up
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= WaitToRampUp);
//    Next_Ramp_Time = (WaitToRampUp + Ramp_Time_Increment);// Different for this first one
//    This_PWM = 0 + Ramp_PWM_Increment;// Different for this first one
//    analogWrite(Section, This_PWM);
//
//    Serial.print("Next_Ramp_Time: ");
//    Serial.println(Next_Ramp_Time);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM + Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    Serial.print("Next_Ramp_Time: ");
//    Serial.println(Next_Ramp_Time);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM + Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM + Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM + Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM + Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM + Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM + Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//
//
//    // Ramp Down
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= StartRampDown);
//    Next_Ramp_Time = (StartRampDown + Ramp_Time_Increment);// Different for this first one
//    This_PWM = PWM_HIGH - Ramp_PWM_Increment;// Different for this first one
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM - Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM - Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM - Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM - Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM - Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM - Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
//    This_PWM = This_PWM - Ramp_PWM_Increment;
//    analogWrite(Section, This_PWM);
//
//
//    // Go Off
//    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
//    analogWrite(Section, PWM_LOW);
//    if (Print_Serial) {
//      Serial_Off(Section, Next_Ramp_Time );
//    }
//
//    PT_END(pt);
//  }
//}
