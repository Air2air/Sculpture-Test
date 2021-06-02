
int SEC_A_PWM = 0;

int Duration = 1000;

unsigned int SleepTime_A = 0;

int RunSectionA(struct pt* pt) {

  PT_BEGIN(pt);
  for (;;) {
    Wait_A = random(WaitMin, WaitMax);// Needs to stay inside this scope

    SleepTime_A = Wait_A;
    SEC_A_PWM = LOW;
    Serial.print("\nSection ");
    Serial.print (SEC_A);
    Serial.print(" waiting Low for: ");
    Serial.println(Wait_A);
    analogWrite(SEC_A, SEC_A_PWM);
    PT_SLEEP(pt, SleepTime_A);

    NumRampLoops = 0;
    SEC_A_PWM = 0;
    while (NumRampLoops <= 5) {
      SleepTime_A = Ramp_Time_Increment;
      NumRampLoops++;
      SEC_A_PWM = SEC_A_PWM + Ramp_PWM_Increment;
      Serial.print("Loop ");
      Serial.print (NumRampLoops);
      Serial.print(" for ");
      Serial.print (SEC_A);
      Serial.print(" Ramping Up at ");
      Serial.print(SleepTime_A);
      Serial.print("ms at ");
      Serial.print(SEC_A_PWM );
      Serial.print(", inc ");
      Serial.print(Ramp_PWM_Increment );
      Serial.println(".");

      analogWrite(SEC_A, SEC_A_PWM);
      PT_SLEEP(pt, SleepTime_A);
    }


    PT_SLEEP(pt, Duration);

  }
  PT_END(pt);
}

int RunSectionB(struct pt* pt) {
  PT_BEGIN(pt);
  for (;;) {
    Wait_B = random(WaitMin, WaitMax);// Needs to stay inside this scope
    Serial.print("\nSection ");
    Serial.print (SEC_B);
    Serial.print(" waiting Low for: ");
    Serial.println(Wait_B);
    analogWrite(LED_BUILTIN, LOW);
    PT_SLEEP(pt, Wait_B);

    Serial.print("Section: ");
    Serial.print (SEC_B);
    Serial.print(" going High for: ");
    Serial.println(Duration);
    analogWrite(LED_BUILTIN, HIGH);
    PT_SLEEP(pt, Duration);
  }
  PT_END(pt);
}

int RunSectionC(struct pt* pt) {
  PT_BEGIN(pt);
  for (;;) {
    Wait_C = random(WaitMin, WaitMax);// Needs to stay inside this scope
    Serial.print("\nSection ");
    Serial.print (SEC_C);
    Serial.print(" waiting Low for: ");
    Serial.println(Wait_C);
    analogWrite(LED_BUILTIN, LOW);
    PT_SLEEP(pt, Wait_C);

    Serial.print("Section: ");
    Serial.print (SEC_C);
    Serial.print(" going High for: ");
    Serial.println(Duration);
    analogWrite(LED_BUILTIN, HIGH);
    PT_SLEEP(pt, Duration);
  }
  PT_END(pt);
}

int RunSectionD(struct pt* pt) {
  PT_BEGIN(pt);
  for (;;) {
    Wait_D = random(WaitMin, WaitMax);// Needs to stay inside this scope
    Serial.print("\nSection ");
    Serial.print (SEC_D);
    Serial.print(" waiting Low for: ");
    Serial.println(Wait_D);
    analogWrite(LED_BUILTIN, LOW);
    PT_SLEEP(pt, Wait_D);

    Serial.print("Section: ");
    Serial.print (SEC_D);
    Serial.print(" going High for: ");
    Serial.println(Duration);
    analogWrite(LED_BUILTIN, HIGH);
    PT_SLEEP(pt, Duration);
  }
  PT_END(pt);
}



static struct pt pt_A_, pt_B_, pt_C_, pt_D_;

void setup() {

  Serial.begin(115200);
  while (! Serial);

  PT_INIT(&pt_A_);
  PT_INIT(&pt_B_);
  PT_INIT(&pt_C_);
  PT_INIT(&pt_D_);

  pinMode(LED_BUILTIN, OUTPUT);

  randomSeed(analogRead(0));
}


void loop() {

  PT_SCHEDULE(RunSectionA(&pt_A_));
  PT_SCHEDULE(RunSectionB(&pt_B_));
  PT_SCHEDULE(RunSectionC(&pt_C_));
  PT_SCHEDULE(RunSectionD(&pt_D_));
}
