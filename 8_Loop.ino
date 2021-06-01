
unsigned long previousMillis = 0;
unsigned long SeedValue = 0;


void setup() {
  pinMode(SEC_A, OUTPUT);
  pinMode(SEC_B, OUTPUT);
  pinMode(SEC_C, OUTPUT);
  pinMode(SEC_D, OUTPUT);

  PT_INIT(&pt1);
  PT_INIT(&pt2);
  PT_INIT(&pt3);
  PT_INIT(&pt4);

  reseedRandom( &reseedRandomSeed);

  Serial.begin(115200);
  while (! Serial);

  analogWrite(SEC_A, 0);
  analogWrite(SEC_B, 0);
  analogWrite(SEC_C, 0);
  analogWrite(SEC_D, 0);
}

void loop() {

  SeedValue = analogRead(A0);

  ChooseSection();

  //Run(&pt1, SEC_A);
  //Run(&pt2, SEC_B);

  //  Run_A_(&pt1);
  //  Run_B_(&pt2);
  //  Run_C_(&pt3);
  //  Run_D_(&pt4);
}
