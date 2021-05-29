
unsigned long previousMillis = 0;

void loop() {

  unsigned long SeedValue = analogRead(A0);
  reseedRandom( &reseedRandomSeed );

  Run_A_(&pt1);
  Run_B_(&pt2);
  Run_C_(&pt3);
  Run_D_(&pt4);
}
