



int RunSection_B(struct pt* pt) {
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

int RunSection_C(struct pt* pt) {
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

int RunSection_D(struct pt* pt) {
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



static struct pt pt_A, pt_B, pt_C, pt_D;

void setup() {

  Serial.begin(115200);
  while (! Serial);

  PT_INIT(&pt_A);
  PT_INIT(&pt_B);
  PT_INIT(&pt_C);
  PT_INIT(&pt_D);

  pinMode(LED_BUILTIN, OUTPUT);

  randomSeed(analogRead(0));
}


void loop() {

  PT_SCHEDULE(RunSection_A(&pt_A));
  PT_SCHEDULE(RunSection_B(&pt_B));
  PT_SCHEDULE(RunSection_C(&pt_C));
  PT_SCHEDULE(RunSection_D(&pt_D));
}
