#include <EEPROM.h>
const short butLinksDown = 9;
const short butPlayPause = 10;
const short butRechtsUp = 11;
const short butBreak = 8;
const short led0 = 4;
const short led1 = 5;
const short led2 = 6;
const short led3 = 7;
const short ledPlayPause = 3;
const short buzzer1 = 2;



bool butStatStart = 0;
bool butStatLinksDown = 0;
bool butStatRechtsUp = 0;
bool butStatPlayPause = 0;
bool butStatBreak = 0;
short ledLichtZaehler = 0;

unsigned char maxLieder = 11;  //max 15; min 1


//Liederarrays
short melody1[] = {   //Happy Birthday 2 Strophen
  238, 238, 267, 238, 317, 297,
  238, 238, 267, 238, 356, 317,
  238, 238, 475, 396, 317, 297, 267,
  419, 419, 396, 317, 356, 317
};
short noteDurations1[] = {
  200, 200, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 950
};
/*  //has to be in the EEProm from adress 90 to 140
unsigned char pausDurations1[] = { 100,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 200,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50
};
*/

/* //has to be in the EEProm from adress 141 to 170
unsigned char melody2[] = {  //Leise rieselt der Schnee
  220, 220, 196, 220, 196, 174, 174, 174, 146, 174, 164, 146, 130, 130, 196, 184, 196, 246, 220, 196,
  174, 174, 196, 146, 146, 164, 146, 164, 174, 174
};
*/
short noteDurations2[] = { 
  950, 450, 700, 200, 450, 1450, 1450, 950, 450, 700, 200, 450, 1450, 1450, 700, 200, 450, 450,
  450, 450, 1450, 1450, 700, 200, 450, 450, 450, 450, 1450, 1450
};
/*  //has to be in the EEProm from adress 1 to 31
unsigned char pausDurations2[] = { 100,
  50, 50, 50, 50, 50, 0, 50, 50, 50, 50, 50, 50, 0, 50, 50, 50, 50, 50,
  50, 50, 0, 50, 50, 50, 50, 50, 50, 50, 0, 50
};
*/

short melody3[] = {   // Super Mario Brostheme  //tempo 200
    /*More songs available at https://github.com/robsoncouto/arduino-songs       
                                              Robson Couto, 2019*/
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo
  659, 8, 659, 8, 0, 8, 659, 8, 0, 8, 523, 8, 659, 8,
  784, 4, 0, 4, 392, 8, 0, 4,
  523, -4, 392, 8, 0, 4, 330, -4,
  440, 4, 494, 4, 466, 8, 440, 4,
  392, -8, 659, -8, 784, -8, 698, 8, 784, 8,
  0, 8, 659, 4, 523, 8, 587, 8, 494, -4,
  523, -4, 392, 8, 0, 4, 330, -4,
  440, 4, 494, 4, 466, 8, 440, 4,
  392, 8, 659, -8, 784, -8, 698, 8, 784, 8,
  0, 8, 659, 4, 523, 8, 587, 8, 494, 4,

  0, 4, 784, 8, 740, 8, 698, 8, 622, 4, 659, 8,
  0, 8, 415, 8, 440, 8, 261, 8, 0, 8, 440, 8, 523, 8, 587, 8,
  0, 4, 622, 4, 0, 8, 587, 4,
  523, 2, 0, 2,
};


short melody4[] = {   //StarWars
  196, 196, 196, 155, 233, 196, 155, 233, 196, 
  293, 293, 293, 311, 233, 185, 155, 233, 196
};
short noteDurations4[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 1000,
  500, 500, 500, 350, 150, 500, 350, 150, 1000
};


short melody5[] = { // Game of Thrones  //tempo 85
  // Score available at https://musescore.com/user/8407786/scores/2156716
  392,8, 262,8, 311,16, 349,16, 392,8, 262,8, 311,16, 349,16, //1
  392,8, 262,8, 311,16, 349,16, 392,8, 262,8, 311,16, 349,16,
  392,-4, 262,-4, 311,16, 349,16, 392,4, 262,4, 311,16,
  349,16, 294,-1, 349,-4, 233,-4, 311,16, 294,16, 349,4,
  233,-4, 311,16, 294,16, 262,-1, 392,-4, 262,-4,
  311,16, 349,16, 392,4, 262,4, 311,16, 349,16, 294,-1,
  349,-4, 233,-4, 311,16, 294,16, 349,4, 233,-4,
  311,16, 294,16, 262,-1, 392,-4, 262,-4,
  311,16, 349,16, 392,4, 262,4, 311,16, 349,16, 294,-2,
};


short melody6[] = {//a million Dream (the greates Showman)
  246, 246, 261, 294, 294, 261, 246, 261, 294, 294, 261, 246, 261, 294, 294, 261, 
  330, 330, 261, 246, 246, 196, 220, 246, 294, 330
};
short noteDurations6[] = {
  200, 450, 200, 225, 725, 200, 450, 200, 225, 725, 200, 450, 200, 225, 475, 200,
  225, 475, 200, 225, 1475, 200, 200, 950, 950, 950
};
/*  //has to be on EEPROM from adress 64 to 89
unsigned char pausDurations6[] = { 50,
  50, 50, 0, 50, 50, 50, 50, 0, 50, 50, 50, 50, 0, 50, 50, 
  0, 50, 50, 0, 50, 50, 50, 50, 50, 50
};
*/

short melody7[] = {//Für Elise (Beethoven)
  330, 311, 330, 311, 330, 246, 294, 261, 220, 130, 330, 220, 246, 330, 208, 246, 261, 330, 311, 
  330, 311, 330, 246, 294, 261, 220, 130, 330, 220, 246, 261, 246, 220
};
short noteDurations7[] = {
  171, 171, 171, 171, 171, 171, 171, 171, 632, 171, 171, 171, 491, 171, 171, 171, 391, 
  171, 171, 171, 171, 171, 171, 171, 171, 632, 171, 171, 171, 491, 171, 171, 391
};
short pausDurations7[] = { 100,
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 150, 50, 50, 50, 491, 
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 150, 50, 50, 50
};


short melody8[] = { //Hes the Pirat (Fluch der Karibik)
  220, 261, 293, 293, 293, 329, 349, 349, 349, 392, 329, 329, 293, 261, 261, 293, 
  220, 261, 293, 293, 293, 329, 349, 349, 349, 392, 329, 329, 293, 261, 293
};
short noteDurations8[] = { 
  200, 200, 450, 450, 200, 200, 450, 450, 200, 200, 450, 450, 
  200, 200, 200, 450, 200, 200, 450, 450, 200, 200, 450, 450, 
  200, 200, 450, 450, 200, 200, 700
};
/*  //eeprom adress 32 to 63
unsigned char pausDurations8[] = { 100,
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 
  50, 50, 50, 250, 50, 50, 50, 50, 50, 50, 50, 50, 
  50, 50, 50, 50, 50, 50, 50
};
*/

short melody9[] = {//Wham Last Christmas
  329, 329, 294, 220, 329, 329, 370, 294, 247, 247,
  329, 329, 370, 294, 247, 277, 294, 277, 247, 370,
  329, 247, 370, 392, 370, 329, 247, 277, 294, 277,
  277, 294, 277, 220
};
short noteDurations9[] = {
  495, 360, 360, 223, 223, 223, 223, 360, 223, 223,
  223, 223, 360, 360, 223, 223, 223, 223, 768, 768,
  495, 223, 223, 223, 223, 495, 223, 223, 223, 223,
  300, 300, 300, 1000
};


short melody10[] = { //Theme from Mission: Impossible by Lalo Schifrin
  220, 220, 262, 294, 220, 220, 196, 208, 220, 220, 262, 294, 220, 220, 196, 208, 
  262, 220, 164, 262, 220, 312, 262, 220, 146, 130, 146
};
short noteDurations10[] = { 
  303, 480, 303, 303, 303, 480, 303, 303, 303, 480, 303, 303, 303, 480, 303, 303,
  126, 126, 1362, 126, 126, 1362, 126, 126, 1362, 126, 1000
};
short pausDurations10[] = { 100,
  353, 50, 50, 50, 353, 50, 50, 50, 353, 50, 50, 50, 353, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50
};


short melody11[] = {  //I'm Blue
  466, 293, 392, 466, 523, 349, 440, 466, 392, 466, 587, 622, 392, 587, 523, 466, 293, 392,
  466, 523, 349, 440, 466, 392, 466, 587, 622, 392, 587, 523, 466, 293, 392, 466, 523, 349,
  440, 466, 392, 466, 587, 622, 392, 587, 523, 466, 293, 392, 466, 440, 261, 349, 392, 466,
  349, 392, 349, 392, 440, 466, 293, 392, 466, 523, 349, 440, 466, 392, 466, 587, 622, 392,
  587, 523, 466, 293, 392, 466, 523, 349, 440, 466, 392, 466, 587, 622, 392, 587, 523, 466,
  293, 392, 466, 523, 349, 440, 466, 392, 466, 587, 622, 392, 587, 523, 466, 293, 392, 466,
  440, 261, 349, 392
};
short noteDurations11[] = { 
  211, 211, 211, 211, 211, 211, 211, 472, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 
  211, 211, 211, 472, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 472, 
  211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 472, 211, 211, 472, 211, 
  211, 211, 211, 211, 211, 211, 211, 211, 211, 472, 211, 211, 211, 211, 211, 211, 211, 211, 211, 
  211, 211, 211, 211, 211, 472, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 
  211, 472, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 472
};

short melodyino[] = {  //Intro
  233, 233, 294, 233, 294, 233
};
short noteDurationsino[] = { 
  250, 100, 400, 250, 250, 250, 850
};

//Function prototypes
void ar2song(short melody[], short noteDurations[], unsigned char arraySize);
bool pauseLoop();
void ledlichter(short a);
void ar1song(short melody[], unsigned char tempo, unsigned char arraySize);
void ar3song(short melody[], short noteDurations[], short pausDurations[], unsigned char arraySize);
void ar3esong(unsigned char eepromstartmelo, short noteDurations[], unsigned char eepromstart, unsigned char arraySize);
void ar3esong(short melody[], short noteDurations[], unsigned char eepromstart, unsigned char arraySize);
void ar3e2song(short melody[], short noteDurations[], unsigned char eepromstart, unsigned char arraySize);
void playSong(unsigned char a);

void setup(){
pinMode(butRechtsUp, INPUT_PULLUP);
pinMode(butLinksDown, INPUT_PULLUP);
pinMode(butPlayPause, INPUT_PULLUP);
pinMode(butBreak, INPUT_PULLUP);
pinMode(ledPlayPause, OUTPUT);
pinMode(led0, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(buzzer1, OUTPUT);
ar2song(melodyino, noteDurationsino, sizeof(melodyino) / sizeof(melodyino[0]));
}


bool pauseLoop () {
  unsigned char helligkeit=0;
  digitalWrite(ledPlayPause, HIGH);
    while (true) 
    {
      helligkeit += 20;
      if (helligkeit>200){
        helligkeit=20;
      }
      analogWrite(ledPlayPause, helligkeit);
      delay(300);
      butStatLinksDown = !digitalRead(butLinksDown);
      butStatRechtsUp = !digitalRead(butRechtsUp);
      butStatPlayPause = !digitalRead(butPlayPause);   //Play
      butStatBreak = !digitalRead(butBreak);
      if (butStatPlayPause)
      {
        delay(500);
        digitalWrite(ledPlayPause, LOW);
        return 0;
      }
      if(butStatBreak)
      {
       digitalWrite(ledPlayPause, LOW);
       break;
      }
      if(butStatLinksDown||butStatRechtsUp)
      {
       digitalWrite(ledPlayPause, LOW);
       return 1;
      }
    }
  digitalWrite(ledPlayPause, LOW);
}


void ledlichter(short a) {
  if(a>maxLieder){   //setzt a
    a = 0;
    ledLichtZaehler = 0;
  }
  else if(a<0){   //setzt a
    a = maxLieder;
    ledLichtZaehler = maxLieder;
  }
  digitalWrite(led3, (a & 8));    //prüft, ob a im 4ten bit = 1 ist (8=2^3=^4.bit)
  digitalWrite(led2, (a & 4));
  digitalWrite(led1, (a & 2));
  digitalWrite(led0, (a & 1));
}


void ar1song(short melody[], unsigned char tempo, unsigned char arraySize) {
  unsigned char notes = arraySize / 2;
  int wholenote = (60000 * 4) / tempo;
  short divider = 0, noteDuration = 0;
  for (unsigned char thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    if (butStatBreak)
    {
      break;
    }
    else
    {
      if (butStatPlayPause)
      {
        bool ret=0;
        ret = pauseLoop();
        if(ret)
        {
          break;
        }
      }
      else
      {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer1, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer1);
  }
  }
  }
}

void ar2song(short melody[], short noteDurations[], unsigned char arraySize) { 
  delay(50);
  for (unsigned char curentNote = 0; curentNote < arraySize; curentNote++)
  {
    butStatPlayPause = !digitalRead(butPlayPause);   //nur Pause
    butStatBreak = !digitalRead(butBreak);
    delay(50);
      if(butStatBreak)
      {
       break;
      }
        else
        {
         if (butStatPlayPause) //macht pause, durch while loop, geht erst weigter nach erneuten button drücken mit delay
          {
            bool ret=0;
            ret = pauseLoop();
            if(ret)
            {
             break;
            }
          } 
            else  //eine Note im Array abspielen und eine pause machen nach der Note (Pause durch array oder dauerhafte zeit festlegen)
            {
              short noteDuration = noteDurations[curentNote];
              tone(buzzer1, melody[curentNote]);
             delay(noteDuration);

             noTone(buzzer1);
            }
        }
  }
}

void ar3song(short melody[], short noteDurations[], short pausDurations[], unsigned char arraySize) { 
  for (unsigned char curentNote = 0; curentNote < arraySize; curentNote++) {
    short pauseDuration = pausDurations[curentNote];
    bool butStatPlayPause = !digitalRead(butPlayPause); // Read the play/pause button
    bool butStatBreak = !digitalRead(butBreak);

    delay(pauseDuration);
    
    if (butStatBreak) {
      break; // Exit the loop if the break button is pressed
    } else {
      if (butStatPlayPause) { // Pause functionality
        bool ret = 0;
        ret = pauseLoop(); // Pause until button is pressed again
        if (ret) {
          break;
        }
      } else { // Play the current note and pause
        short noteDuration = noteDurations[curentNote];
        tone(buzzer1, melody[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

void ar3esong(unsigned char eepromstartmelo, short noteDurations[], unsigned char eepromstart, unsigned char arraySize) {
  for (unsigned short curentNote = 0; curentNote < arraySize; curentNote++)
  {
    unsigned char pauseDuration = EEPROM.read(0+eepromstart+curentNote);
    butStatPlayPause = !digitalRead(butPlayPause);   //nur Pause
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);
    if(butStatBreak){
     break;
    }
    else{
      if (butStatPlayPause){
        bool ret=0;
        ret = pauseLoop();
        if(ret){
          break;
        }
      } 
      else{
        short noteDuration = noteDurations[curentNote];
        tone(buzzer1, EEPROM.read(0+eepromstartmelo+curentNote));
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

void ar3esong(short melody[], short noteDurations[], unsigned char eepromstart, unsigned char arraySize) {
  for (unsigned short curentNote = 0; curentNote < arraySize; curentNote++)
  {
    unsigned char pauseDuration = EEPROM.read(0+eepromstart+curentNote);
    butStatPlayPause = !digitalRead(butPlayPause);   //nur Pause
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);
    if(butStatBreak){
     break;
    }
    else{
      if (butStatPlayPause){
        bool ret=0;
        ret = pauseLoop();
        if(ret){
          break;
        }
      } 
      else{
        short noteDuration = noteDurations[curentNote];
        tone(buzzer1, melody[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

//array wiederholen, ohne wiederholung der Pausen aus EEPROM
void ar3e2song(short melody[], short noteDurations[], unsigned char eepromstart, unsigned char arraySize) {
  for (unsigned short curentNote = 0; curentNote < arraySize; curentNote++)
  {
    unsigned char pauseDuration = EEPROM.read(0+eepromstart+curentNote);
    butStatPlayPause = !digitalRead(butPlayPause);   //nur Pause
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);
    if(butStatBreak){
     break;
    }
    else{
      if (butStatPlayPause){
        bool ret=0;
        ret = pauseLoop();
        if(ret){
          break;
        }
      } 
      else{
        short noteDuration = noteDurations[curentNote];
        tone(buzzer1, melody[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
  for (unsigned short curentNote = 0; curentNote < arraySize; curentNote++)
  {
    unsigned char pauseDuration = EEPROM.read(0+eepromstart+curentNote+arraySize);
    butStatPlayPause = !digitalRead(butPlayPause);   //nur Pause
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);
    if(butStatBreak){
     break;
    }
    else{
      if (butStatPlayPause){
        bool ret=0;
        ret = pauseLoop();
        if(ret){
          break;
        }
      } 
      else{
        short noteDuration = noteDurations[curentNote];
        tone(buzzer1, melody[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}


void playSong (unsigned char a) {
switch (a) {
case 1: {
  ar3e2song(melody1, noteDurations1, 90, sizeof(melody1) / sizeof(melody1[0]));
  break;
}
case 2: {
  ar3esong(141, noteDurations2, 1, sizeof(noteDurations2) / sizeof(noteDurations2[0]));
  break;
}

case 3: {
  const unsigned char tempo = 200;
  ar1song(melody3, tempo, sizeof(melody3) / sizeof(melody3[0]));
  break;
}

case 4: {
  ar2song(melody4, noteDurations4, sizeof(melody4) / sizeof(melody4[0]));
  break;
}

case 5: {
  const unsigned char tempo = 85;
  ar1song(melody5, tempo, sizeof(melody5) / sizeof(melody5[0]));
  break;
}

case 6: {
  ar3esong(melody6, noteDurations6, 64, sizeof(melody6) / sizeof(melody6[0]));
  break;
}

case 7: {
  ar3song(melody7, noteDurations7, pausDurations7, sizeof(melody7) / sizeof(melody7[0]));
  break;
}

case 8: {
  ar3esong(melody8, noteDurations8, 32, sizeof(melody8) / sizeof(melody8[0]));
  break;
}

case 9: {
  ar2song(melody9, noteDurations9, sizeof(melody9) / sizeof(melody9[0]));
  break;
}

case 10:{
  ar3song(melody10, noteDurations10, pausDurations10, sizeof(melody10) / sizeof(melody10[0]));
  break;
}

case 11:{
    ar2song(melody11, noteDurations11, sizeof(melody11) / sizeof(melody11[0]));
    break;
}
}
}


void loop() {
  butStatBreak = !digitalRead(butBreak);
  butStatLinksDown = !digitalRead(butLinksDown);
  butStatRechtsUp = !digitalRead(butRechtsUp);
  butStatPlayPause = !digitalRead(butPlayPause);
  static unsigned char b = 0;
  if (butStatBreak)
  {
    if (b)
    { 
    b=0;
    }else {
      b=1;
      }
  }
  
  if (butStatLinksDown)
  {
    ledLichtZaehler = ledLichtZaehler + 1 + b;
    ledlichter(ledLichtZaehler);
  }

  if (butStatRechtsUp)
  {
    ledLichtZaehler = ledLichtZaehler - 1 - b;
    ledlichter(ledLichtZaehler);
  }

  if (butStatPlayPause && ledLichtZaehler>0)
  {
    delay(500);
    playSong(ledLichtZaehler);
  }
  delay(300);
}
