

static int Run_C_(struct pt * pt) {
  static unsigned long PWM_High = PWM_HIGH;
  static unsigned long Section = SEC_C;
  static unsigned long Wait = SEC_C_WAIT;
  static unsigned long Duration = SEC_C_DURATION;
 // static unsigned long Ramp_Time_Increment = SEC_C_PWM_INCREMENT;
  static unsigned long Start_Time_Marker;
  static unsigned long StartRampUp = Wait;
  static unsigned long StartRampDown = Wait + Duration;
  static unsigned long GoOffTime;
  static unsigned long Stay_Off_Time;
  static unsigned long This_PWM;
  static unsigned long Next_Ramp_Time;

  PT_BEGIN(pt);
  while (1) {
    Start_Time_Marker = millis();

    //Start
    if (Print_Serial) {
      Serial_Start(Section, Wait);
    }

    // Ramp Up
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= StartRampUp);
    Next_Ramp_Time = (StartRampUp + Ramp_Time_Increment);// Different for this first one
    This_PWM = 0 + Ramp_PWM_Increment;// Different for this first one
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM + Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM + Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM + Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM + Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM + Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM + Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM + Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);



    // Ramp Down
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= StartRampDown);
    Next_Ramp_Time = (StartRampDown + Ramp_Time_Increment);// Different for this first one
    This_PWM = PWM_High - Ramp_PWM_Increment;// Different for this first one
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Section, This_PWM);





    // Go Off
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    GoOffTime = Next_Ramp_Time;
    Stay_Off_Time = Run_Duration - Next_Ramp_Time;
    Analog_Write(Section, PWM_LOW);
    if (Print_Serial) {
      Serial_Off(Section, Next_Ramp_Time, Stay_Off_Time );
    }

    // Run duration ended
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Run_Duration); // End Loop if stride duration has elapsed
    if (Print_Serial) {
      Serial_End(Section, Run_Duration);
    }
    PT_END(pt);
  }
}