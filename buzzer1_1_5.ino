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

int maxLieder = 9;  //max 15; min 1


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

int melody3[] = {   // Super Mario Brostheme
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


int melody4[] = {   //StarWars
  196, 196, 196, 155, 233, 196, 155, 233, 196, 
  293, 293, 293, 311, 233, 185, 155, 233, 196
};
int noteDurations4[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 1000,
  500, 500, 500, 350, 150, 500, 350, 150, 1000
};
int pausDurations4[] = {
  100,
  50, 50, 50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50, 50, 50
};


int melody5[] = {
  // Game of Thrones
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
    while (true) 
    {
      delay(300);
      butStatLinksUp = !digitalRead(butLinksUp);
      butStatRechtsDown = !digitalRead(butRechtsDown);
      butStatPlayPause = !digitalRead(butPlayPause);   //Play
      butStatBreak = !digitalRead(butBreak);
      if (butStatPlayPause)
      {
        delay(700);
        break;
      }
      if(butStatBreak)
      {
       digitalWrite(ledPlayPause, LOW);
       break;
      }
      if(butStatLinksUp||butStatRechtsDown)
      {
       digitalWrite(ledPlayPause, LOW);
       loop();
      }
    }
  digitalWrite(ledPlayPause, LOW);
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
  int tempo = 85;
  int notes = sizeof(melody5) / sizeof(melody5[0]) / 2;
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
    divider = melody5[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer1, melody5[thisNote], noteDuration * 0.9);
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
  loop();
}
