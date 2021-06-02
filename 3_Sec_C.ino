

unsigned int SleepTime_C = 0;
int SEC_C_PWM = 0;
int Wait_C = 0;

int RunSection_C(struct pt* pt) {

  PT_BEGIN(pt);
  for (;;) {
    Wait_C = random(WaitMin, WaitMax);// Needs to stay inside this scope

    SleepTime_C = Wait_C;
    SEC_C_PWM = LOW;

    if (SerialMonitor) {
      Serial.print("Section ");
      Serial.print (SEC_C);
      Serial.print(" waiting Low for: ");
      Serial.println(Wait_C);
    }
    analogWrite(SEC_C, SEC_C_PWM);
    PT_SLEEP(pt, SleepTime_C);

    RampLoopIndex = 0;
    SEC_C_PWM = 0;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_C = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_C_PWM = SEC_C_PWM + Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_C);
        Serial.print(" Ramp Up ");
        Serial.print(SleepTime_C);
        Serial.print("ms at ");
        Serial.print(SEC_C_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_C, SEC_C_PWM);
      PT_SLEEP(pt, SleepTime_C);
    }

    if (SerialMonitor) {
      Serial.print("Pin ");
      Serial.print (SEC_C);
      Serial.print(" Holding for ");
      Serial.print(Duration);
      Serial.print("ms at ");
      Serial.print(SEC_C_PWM );
      Serial.println(".");
    }
    analogWrite(SEC_C, SEC_C_PWM);
    PT_SLEEP(pt, Duration);

    RampLoopIndex = 0;
    SEC_C_PWM = PWM_HIGH;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_C = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_C_PWM = SEC_C_PWM - Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_C);
        Serial.print(" Ramp Down ");
        Serial.print(SleepTime_C);
        Serial.print("ms at ");
        Serial.print(SEC_C_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_C, SEC_C_PWM);
      PT_SLEEP(pt, SleepTime_C);
    }

  }
  PT_END(pt);
}
