
/*--- Biasing ----*/
unsigned long SEC_A_PWM_HIGH = PWM_HIGH * _A_Bias;
unsigned long SEC_B_PWM_HIGH = PWM_HIGH * _B_Bias;
unsigned long SEC_C_PWM_HIGH = PWM_HIGH * _C_Bias;
unsigned long SEC_D_PWM_HIGH = PWM_HIGH * _D_Bias;

/*--- Ramp Increment ----*/
//unsigned long SEC_A_PWM_INCREMENT = SEC_A_PWM_HIGH / 8 ;
//unsigned long SEC_B_PWM_INCREMENT = SEC_B_PWM_HIGH / 8 ;
//unsigned long SEC_C_PWM_INCREMENT = SEC_C_PWM_HIGH / 8 ;
//unsigned long SEC_D_PWM_INCREMENT = SEC_D_PWM_HIGH / 8 ;


unsigned long PWM_VAL = 0;


/*--- Analog Write ----*/
void Analog_Write(int Section, int PWM_VAL) {
  Print_Section(Section);
  if (PWM_VAL <= 0) {
    analogWrite(Section, 0);
    if (Print_Serial) {
      Serial.println("PWM BELOW 0");
    }
  }
  else {
    analogWrite(Section, PWM_VAL);
    if (Print_Serial) {
      Serial.print(" PWM ");
      Serial.println(PWM_VAL);
    }
  }
}
