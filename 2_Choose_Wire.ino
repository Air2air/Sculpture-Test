

/*---------- Section Choice for 4 wires -----------*/
int ActiveSection = SEC_D;// Just for Startup
int PreviousSection;
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
        Serial.print(PreviousSection);
        Serial.print(".\n");
      }
      SectionChoice1 = SEC_B;
      SectionChoice2 = SEC_C;
      SectionChoice3 = SEC_D;
    } else if ( PreviousSection == SEC_B) {
      if (Print_Serial) {
        Serial.print("PreviousSection was pin ");
        Serial.print(PreviousSection);
        Serial.print(".\n");
      }
      SectionChoice1 = SEC_A;
      SectionChoice2 = SEC_C;
      SectionChoice3 = SEC_D;
    } else if ( PreviousSection == SEC_C) {
      if (Print_Serial) {
        Serial.print("PreviousSection was pin ");
        Serial.print(PreviousSection);
        Serial.print(".\n");
      }
      SectionChoice1 = SEC_A;
      SectionChoice2 = SEC_B;
      SectionChoice3 = SEC_D;
    } else {
      if (Print_Serial) {
        Serial.print("PreviousSection was pin ");
        Serial.print(PreviousSection);
        Serial.print(".\n");
      }
      SectionChoice1 = SEC_A;
      SectionChoice2 = SEC_B;
      SectionChoice3 = SEC_C;
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
  
  return ActiveSection;
  return PreviousSection;

}
