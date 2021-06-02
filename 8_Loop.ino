
static struct pt pt_A, pt_B, pt_C, pt_D;

void setup() {

  pinMode(SEC_A, OUTPUT);
  pinMode(SEC_B, OUTPUT);
  pinMode(SEC_C, OUTPUT);
  pinMode(SEC_D, OUTPUT);

  analogWrite(SEC_A, 0);
  analogWrite(SEC_B, 0);
  analogWrite(SEC_C, 0);
  analogWrite(SEC_D, 0);

  Serial.begin(115200);
  while (! Serial);

  PT_INIT(&pt_A);
  PT_INIT(&pt_B);
  PT_INIT(&pt_C);
  PT_INIT(&pt_D);

  randomSeed(analogRead(0));
}

void loop() {
  PT_SCHEDULE(RunSection_A(&pt_A));
  PT_SCHEDULE(RunSection_B(&pt_B));
  PT_SCHEDULE(RunSection_C(&pt_C));
  PT_SCHEDULE(RunSection_D(&pt_D));
}
