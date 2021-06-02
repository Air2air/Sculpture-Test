

unsigned int SleepTime_D = 0;
int SEC_D_PWM = 0;
int Wait_D = 0;

int RunSection_D(struct pt* pt) {

  PT_BEGIN(pt);
  for (;;) {
    Wait_D = random(WaitMin, WaitMax);// Needs to stay inside this scope

    SleepTime_D = Wait_D;
    SEC_D_PWM = LOW;
    if (SerialMonitor) {
      Serial.print("Section ");
      Serial.print (SEC_D);
      Serial.print(" waiting Low for: ");
      Serial.println(Wait_D);
    }
    analogWrite(SEC_D, SEC_D_PWM);
    PT_SLEEP(pt, SleepTime_D);

    RampLoopIndex = 0;
    SEC_D_PWM = 0;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_D = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_D_PWM = SEC_D_PWM + Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_D);
        Serial.print(" Ramp Up ");
        Serial.print(SleepTime_D);
        Serial.print("ms at ");
        Serial.print(SEC_D_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_D, SEC_D_PWM);
      PT_SLEEP(pt, SleepTime_D);
    }

    if (SerialMonitor) {
      Serial.print("Pin ");
      Serial.print (SEC_D);
      Serial.print(" Holding for ");
      Serial.print(Duration);
      Serial.print("ms at ");
      Serial.print(SEC_D_PWM );
      Serial.println(".");
    }
    analogWrite(SEC_D, SEC_D_PWM);
    PT_SLEEP(pt, Duration);

    RampLoopIndex = 0;
    SEC_D_PWM = PWM_HIGH;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_D = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_D_PWM = SEC_D_PWM - Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_D);
        Serial.print(" Ramp Down ");
        Serial.print(SleepTime_D);
        Serial.print("ms at ");
        Serial.print(SEC_D_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_D, SEC_D_PWM);
      PT_SLEEP(pt, SleepTime_D);
    }

  }
  PT_END(pt);
}
