
/*--- Biasing ----*/
unsigned long SEC_A_PWM_HIGH = PWM_HIGH * _ABias;
unsigned long SEC_B_PWM_HIGH = PWM_HIGH * _BBias;
unsigned long SEC_C_PWM_HIGH = PWM_HIGH * _CBias;
unsigned long SEC_D_PWM_HIGH = PWM_HIGH * _DBias;

unsigned long PWM_VAL = 0;


//
///*--- Analog Write ----*/
//void analogWrite(int Section, int PWM_VAL) {
//  Print_Section(Section);
//  if (PWM_VAL <= 0) {
//    analogWrite(Section, 0);
//    if (Print_Serial) {
//      Serial.println("PWM BELOW 0");
//    }
//  }
//  else {
//    analogWrite(Section, PWM_VAL);
//    if (Print_Serial) {
//      Serial.print(" PWM: ");
//      Serial.println(PWM_VAL);
//    }
//  }
//}
