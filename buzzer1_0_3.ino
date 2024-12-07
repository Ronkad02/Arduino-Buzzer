const int butStart = 12;
const int butLinksUp = 11;
const int butRechtsDown = 10;
const int butPlayPause = 9;
const int butBreak = 8;
const int ledPlayPause = 7;
const int led0 = 6;
const int led1 = 5;
const int led2 = 4;
const int led3 = 3;
const int buzzer1 =2;

int butStatStart = 0;
int butStatLinksUp = 0;
int butStatRechtsDown = 0;
int butStatPlayPause = 0;
int butStatBreak = 0;

int ledLichtZaehler = 0;
bool playingSong = 0;

int maxLieder = 15;  //max 15; min 1

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


//Liederarrays
int melody1[] = {   //Happy Birthday 2 Strophen
  238, 238, 267, 238, 317, 297,
  238, 238, 267, 238, 356, 317,
  238, 238, 475, 396, 317, 297, 267,
  419, 419, 396, 317, 356, 317,
  238, 238, 267, 238, 317, 297,
  238, 238, 267, 238, 356, 317,
  238, 238, 475, 396, 317, 297, 267,
  419, 419, 396, 317, 356, 317
};
int noteDurations1[] = {
  200, 200, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 450, 950,
  200, 200, 450, 450, 450, 950
};
int pausDurations1[] = {
  100,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 200,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50
};


int melody2[] = {   //Wallermann
  392, 261, 261, 261, 330,
  392, 392, 392, 392, 440,
  349, 349, 349, 349, 440,
  523, 523, 392, 392, 392,
  261, 261, 261, 330, 392,
  392, 392, 392, 392, 349,
  330, 330, 293, 261
};
int noteDurations2[] = {
  450, 450, 450, 450, 450,
  450, 450, 700, 200, 450,
  200, 200, 450, 200, 200,
  200, 200, 450, 700, 200,
  450, 450, 450, 200, 450,
  450, 700, 200, 450, 450,
  200, 200, 450, 950
};
int pausDurations2[] = {
  100,
  50, 50, 50, 50, 50,
  50, 50, 50, 50, 50,
  50, 50, 50, 50, 50,
  50, 50, 50, 50, 50,
  50, 50, 50, 50, 50,
  50, 50, 50, 50, 50,
  50, 50, 50, 50
};

int melody3[] = {
  /* 
  Super Mario Bros - Overworld theme 
  More songs available at https://github.com/robsoncouto/arduino-songs                                                                                      
                                              Robson Couto, 2019
*/
  // Super Mario Bros theme
  // Score available at https://musescore.com/user/2123/scores/2145
  // Theme by Koji Kondo
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
  REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
  REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
  NOTE_C5,2, REST,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
  REST,1, 
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19

  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
  NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
  NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
  REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
  REST,1,

  NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
  NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
  NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
  NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
  NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

  //game over sound
  NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
  NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
  NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  
};

int melody4[] = {};
int noteDurations4[] = {};
int pausDurations4[] = {};

int melody5[] = {};
int noteDurations5[] = {};
int pausDurations5[] = {};

int melody6[] = {};
int noteDurations6[] = {};
int pausDurations6[] = {};

int melody7[] = {};
int noteDurations7[] = {};
int pausDurations7[] = {};

int melody8[] = {};
int noteDurations8[] = {};
int pausDurations8[] = {};

int melody9[] = {};
int noteDurations9[] = {};
int pausDurations9[] = {};



void setup()
{
pinMode(butStart, INPUT_PULLUP);
pinMode(butLinksUp, INPUT_PULLUP);
pinMode(butRechtsDown, INPUT_PULLUP);
pinMode(butPlayPause, INPUT_PULLUP);
pinMode(butBreak, INPUT_PULLUP);
pinMode(ledPlayPause, OUTPUT);
pinMode(led0, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(buzzer1, OUTPUT);
}

void pauseLoop ()
{
  digitalWrite(ledPlayPause, HIGH);
  bool paus=1;
  delay(200);
    while (paus) 
    {
      butStatPlayPause = !digitalRead(butPlayPause);   //Play
      butStatBreak = !digitalRead(butBreak);
      if (butStatPlayPause)
      {
        paus = 0;
      }
      if(butStatBreak)
      {
       digitalWrite(ledPlayPause, LOW);
       break;
      }
      delay(200);
    }
  digitalWrite(ledPlayPause, LOW);
}


void playSong (int a)
{
switch (a)
{
case 1:
{
    song1 ();
    break;
}
case 2:
{
    song2();
    break;
}

case 3: {
    song3();
    break;
}

case 4: {
    song4();
    break;
}

case 5: {
    song5();
    break;
}

case 6: {
    song6();
    break;
}

case 7: {
    song7();
    break;
}

case 8: {
    song8();
    break;
}

case 9: {
    song9();
    break;
}

/*
case 10:

break;
case 11:

break;
case 12:

break;
case 13:

break;
case 14:

break;
case 15:

break;
*/


}
}


void ledlichter(int a)
{
  if(a>maxLieder)   //setzt 
  {
    a = 0;
    ledLichtZaehler = 0;
  }
  if(a<0)   //setzt 
  {
    a = maxLieder;
    ledLichtZaehler = maxLieder;
  }
  if (a==0)                   //wenn a = 0, alles LOW
  {
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else
    {
    if (a%2!=0) 	            //led0 High, wenn a ungerade
    {
      digitalWrite(led0, HIGH);
      a--;
    }
      else
      {
        digitalWrite(led0, LOW);
      }
    
    if (a-8>=0)               //led3 2^3, HiGH, wenn a>=2^3=8
    {
      digitalWrite(led3, HIGH);
      a=a-8;
    }
      else
      {
        digitalWrite(led3, LOW);
     }

        if (a-4>=0)           //led2 2^2, HIGH, wenn a>=2^2=4
    {
      digitalWrite(led2, HIGH);
      a=a-4;
    }
      else
      {
        digitalWrite(led2, LOW);
     }

    if (a-2>=0)               //led1 2^1, HIGH, wenn a>=2
    {
      digitalWrite(led1, HIGH);
      a=a-2;
    }
      else
      {
        digitalWrite(led1, LOW);
     }

  }
  delay(300);
}

void song1()
{ 
  for (int curentNote = 0; curentNote < sizeof(melody1) / sizeof(melody1[0]); curentNote++)
  {
    int pauseDuration = pausDurations1[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);   //nur Pause
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);
      if(butStatBreak)
      {
       break;
      }
        else
        {
         if (butStatPlayPause) //macht pause, durch while loop, geht erst weigter nach erneuten button drücken mit delay
          {
            pauseLoop();
          } 
            else  //eine Note im Array abspielen und eine pause machen nach der Note (Pause durch array oder dauerhafte zeit festlegen)
            {
              int noteDuration = noteDurations1[curentNote];
              tone(buzzer1, melody1[curentNote]);
             delay(noteDuration);

             noTone(buzzer1);
            }
        }
  }
}

void song2()
{ 
  for (int curentNote = 0; curentNote < sizeof(melody2) / sizeof(melody2[0]); curentNote++)
  {
    int pauseDuration = pausDurations2[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);   //nur Pause
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);
      if(butStatBreak)
      {
       break;
      }
        else
        {
         if (butStatPlayPause) //macht pause, durch while loop, geht erst weigter nach erneuten button drücken mit delay
          {
            pauseLoop();
          } 
            else  //eine Note im Array abspielen und eine pause machen nach der Note (Pause durch array oder dauerhafte zeit festlegen)
            {
              int noteDuration = noteDurations2[curentNote];
              tone(buzzer1, melody2[curentNote]);
             delay(noteDuration);

             noTone(buzzer1);
            }
        }
  } 
}

void song3()
{
  int tempo = 200;
  int notes = sizeof(melody3) / sizeof(melody3[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
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
        pauseLoop();
      }
      else
      {
    divider = melody3[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer1, melody3[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer1);
  }
  }
  }
}

void song4()
{
  for (int curentNote = 0; curentNote < sizeof(melody4) / sizeof(melody4[0]); curentNote++)
  {
    int pauseDuration = pausDurations4[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);

    if (butStatBreak)
    {
      break;
    }
    else
    {
      if (butStatPlayPause)
      {
        pauseLoop();
      }
      else
      {
        int noteDuration = noteDurations4[curentNote];
        tone(buzzer1, melody4[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

void song5()
{
  for (int curentNote = 0; curentNote < sizeof(melody5) / sizeof(melody5[0]); curentNote++)
  {
    int pauseDuration = pausDurations5[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);

    if (butStatBreak)
    {
      break;
    }
    else
    {
      if (butStatPlayPause)
      {
        pauseLoop();
      }
      else
      {
        int noteDuration = noteDurations5[curentNote];
        tone(buzzer1, melody5[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

void song6()
{
  for (int curentNote = 0; curentNote < sizeof(melody6) / sizeof(melody6[0]); curentNote++)
  {
    int pauseDuration = pausDurations6[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);

    if (butStatBreak)
    {
      break;
    }
    else
    {
      if (butStatPlayPause)
      {
        pauseLoop();
      }
      else
      {
        int noteDuration = noteDurations6[curentNote];
        tone(buzzer1, melody6[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

void song7()
{
  for (int curentNote = 0; curentNote < sizeof(melody7) / sizeof(melody7[0]); curentNote++)
  {
    int pauseDuration = pausDurations7[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);

    if (butStatBreak)
    {
      break;
    }
    else
    {
      if (butStatPlayPause)
      {
        pauseLoop();
      }
      else
      {
        int noteDuration = noteDurations7[curentNote];
        tone(buzzer1, melody7[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

void song8()
{
  for (int curentNote = 0; curentNote < sizeof(melody8) / sizeof(melody8[0]); curentNote++)
  {
    int pauseDuration = pausDurations8[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);

    if (butStatBreak)
    {
      break;
    }
    else
    {
      if (butStatPlayPause)
      {
        pauseLoop();
      }
      else
      {
        int noteDuration = noteDurations8[curentNote];
        tone(buzzer1, melody8[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}

void song9()
{
  for (int curentNote = 0; curentNote < sizeof(melody9) / sizeof(melody9[0]); curentNote++)
  {
    int pauseDuration = pausDurations9[curentNote];
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    delay(pauseDuration);

    if (butStatBreak)
    {
      break;
    }
    else
    {
      if (butStatPlayPause)
      {
        pauseLoop();
      }
      else
      {
        int noteDuration = noteDurations9[curentNote];
        tone(buzzer1, melody9[curentNote]);
        delay(noteDuration);
        noTone(buzzer1);
      }
    }
  }
}





void loop() {

  butStatStart = !digitalRead(butStart);
  butStatLinksUp = !digitalRead(butLinksUp);
  butStatRechtsDown = !digitalRead(butRechtsDown);

  if (butStatLinksUp)
  {
    ledLichtZaehler = ledLichtZaehler + 1;
    ledlichter(ledLichtZaehler);
  }

  if (butStatRechtsDown)
  {
    ledLichtZaehler = ledLichtZaehler - 1;
    ledlichter(ledLichtZaehler);
  }

  if (butStatStart && ledLichtZaehler>0)
  {
    playingSong = 1;
    playSong(ledLichtZaehler);
  }

}
