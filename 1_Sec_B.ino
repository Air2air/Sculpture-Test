

unsigned int SleepTime_B = 0;
int SEC_B_PWM = 0;
int Wait_B = 0;

int RunSection_B(struct pt* pt) {

  PT_BEGIN(pt);
  for (;;) {
    Wait_B = random(WaitMin, WaitMax);// Needs to stay inside this scope

    SleepTime_B = Wait_B;
    SEC_B_PWM = LOW;
    if (SerialMonitor) {
      Serial.print("Section ");
      Serial.print (SEC_B);
      Serial.print(" waiting Low for: ");
      Serial.println(Wait_B);
    }
    analogWrite(SEC_B, SEC_B_PWM);
    PT_SLEEP(pt, SleepTime_B);

    RampLoopIndex = 0;
    SEC_B_PWM = 0;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_B = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_B_PWM = SEC_B_PWM + Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_B);
        Serial.print(" Ramp Up ");
        Serial.print(SleepTime_B);
        Serial.print("ms at ");
        Serial.print(SEC_B_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_B, SEC_B_PWM);
      PT_SLEEP(pt, SleepTime_B);
    }

    if (SerialMonitor) {
      Serial.print("Pin ");
      Serial.print (SEC_B);
      Serial.print(" Holding for ");
      Serial.print(Duration);
      Serial.print("ms at ");
      Serial.print(SEC_B_PWM );
      Serial.println(".");
    }
    analogWrite(SEC_B, SEC_B_PWM);
    PT_SLEEP(pt, Duration);

    RampLoopIndex = 0;
    SEC_B_PWM = PWM_HIGH;
    while (RampLoopIndex < NumRampLoops) {
      SleepTime_B = Ramp_Time_Increment;
      RampLoopIndex++;
      SEC_B_PWM = SEC_B_PWM - Ramp_PWM_Increment;
      if (SerialRamp) {
        Serial.print("Ramp ");
        Serial.print (RampLoopIndex);
        Serial.print(" pin ");
        Serial.print (SEC_B);
        Serial.print(" Ramp Down ");
        Serial.print(SleepTime_B);
        Serial.print("ms at ");
        Serial.print(SEC_B_PWM );
        Serial.println(".");
      }
      analogWrite(SEC_B, SEC_B_PWM);
      PT_SLEEP(pt, SleepTime_B);
    }

  }
  PT_END(pt);
}
