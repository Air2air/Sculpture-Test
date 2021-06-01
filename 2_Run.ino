

static int Run(struct pt * pt, int Section) {

  int Wait = random(1000, 3000);
  int Start_Time_Marker;
  int StartRampUp = Wait;
  int StartRampDown = Wait + Duration;
  int GoOffTime;
  int Stay_Off_Time;
  int This_PWM;
  int Next_Ramp_Time;


  PT_BEGIN(pt);
  while (1) {
    Start_Time_Marker = Wait + millis();

    //Start
    if (Print_Serial) {
      Serial_Start(Section, Wait);
    }

    Serial.print("Ramp_Time_Increment: ");
    Serial.println(Ramp_Time_Increment);

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
    This_PWM = PWM_HIGH - Ramp_PWM_Increment;// Different for this first one
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
    Analog_Write(Section, PWM_LOW);
    if (Print_Serial) {
      Serial_Off(Section, Next_Ramp_Time );
    }

    PT_END(pt);
  }
}
