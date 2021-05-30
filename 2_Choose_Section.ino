

/*---------- Section Choice for 4 wires -----------*/
int ActiveSection;// Just for Startup
int PreviousSection;// Just for Startup
int RandSectionSelection;
int SectionChoice1;
int SectionChoice2;
int SectionChoice3;

void ChooseSection() {

  if (Print_Serial) {
    Serial.println("\n\n\n---------- 4 Sections ------------");
  }

  if ( PreviousSection == SEC_A) {
    if (Print_Serial) {
      Serial.print("PreviousSection was pin ");
      Serial.print(SEC_A);
      Serial.print(".\n");
    }
    SectionChoice1 = SEC_B;
    SectionChoice2 = SEC_C;
    SectionChoice3 = SEC_D;
    ActiveSection = SEC_A;
  } else if ( PreviousSection == SEC_B) {
    if (Print_Serial) {
      Serial.print("PreviousSection was pin ");
      Serial.print(SEC_B);
      Serial.print(".\n");
    }
    SectionChoice1 = SEC_A;
    SectionChoice2 = SEC_C;
    SectionChoice3 = SEC_D;
    ActiveSection == SEC_B;
  } else if ( PreviousSection == SEC_C) {
    if (Print_Serial) {
      Serial.print("PreviousSection was pin ");
      Serial.print(SEC_C);
      Serial.print(".\n");
    }
    SectionChoice1 = SEC_A;
    SectionChoice2 = SEC_B;
    SectionChoice3 = SEC_D;
    ActiveSection == SEC_C;
  } else {
    if (Print_Serial) {
      Serial.print("PreviousSection was pin ");
      Serial.print(SEC_D);
      Serial.print(".\n");
    }
    SectionChoice1 = SEC_A;
    SectionChoice2 = SEC_B;
    SectionChoice3 = SEC_C;
    ActiveSection == SEC_D;
  }

  RandSectionSelection = random(3);

  if (RandSectionSelection == 0) { // If index[0]
    ActiveSection = SectionChoice1;
  }
  else if (RandSectionSelection == 1) {
    ActiveSection = SectionChoice2;
  }
  else if (RandSectionSelection == 2) {
    ActiveSection = SectionChoice3;
  }

  delay(1000);
  Serial.print("RandSectionSelection: ");
  Serial.println(RandSectionSelection);
  Serial.print("ActiveSection: ");
  Serial.println(ActiveSection);

  PreviousSection = ActiveSection;

}
