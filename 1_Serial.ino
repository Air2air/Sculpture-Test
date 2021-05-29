

void Print_Section(int Section) {
  if (Section == SEC_A) {
    Serial.print("_A_ ");
  } else if (Section == SEC_B) {
    Serial.print("_B_ ");
  } else if (Section == SEC_C) {
    Serial.print("_C_ ");
  } else {
    Serial.print("_D_ ");
  }
}

void Serial_Start(int Section, int Wait) {
  Serial.print("\n");
  Print_Section(Section);
  Serial.print("waiting ");
  Serial.print(Wait);
  Serial.println(" to start.");
}

void Serial_Wait(int Section, int Start_PWM_High, int PWM_High, int Duration ) {
  Print_Section(Section);
  Serial.print("going HIGH at ");
  Serial.print(Start_PWM_High);
  Serial.print(" at ");
  Serial.print(PWM_High);
  Serial.print(" PWM for ");
  Serial.println(Duration);
}

void Serial_Off(int Section, int GoOffTime, int StayOffTime) {
  Print_Section(Section);
  Serial.print("going OFF at ");
  Serial.print(GoOffTime);
  Serial.print(" with ");
  Serial.print(StayOffTime);
  Serial.println(" remaining");
}

void Serial_End(int Section, int EndLoopTime) {
  Serial.print("Ended ");
  Print_Section(Section);
  Serial.print("after ");
  Serial.println(EndLoopTime);
}
