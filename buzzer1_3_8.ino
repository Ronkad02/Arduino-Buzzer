const int butStart = 12;
const int butLinksUp = 11;
const int butRechtsDown = 10;
const int butPlayPause = 9;
const int butBreak = 8;
const int ledPlayPause = 3;
const int led3 = 7;
const int led2 = 6;
const int led1 = 5;
const int led0 = 4;
const int buzzer1 =2;


int butStatStart = 0;
int butStatLinksUp = 0;
int butStatRechtsDown = 0;
int butStatPlayPause = 0;
int butStatBreak = 0;
int b = 1;
int ledLichtZaehler = 0;

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


int melody5[] = { // Game of Thrones
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

int melody6[] = {//a million Dream (the greates Showman)
  246, 246, 261, 294, 294, 261, 246, 261, 294, 294, 261, 246, 261, 294, 294, 261, 
  330, 330, 261, 246, 246, 196, 220, 246, 294, 330
};
int noteDurations6[] = {
  200, 450, 200, 225, 725, 200, 450, 200, 225, 725, 200, 450, 200, 225, 475, 200,
  225, 475, 200, 225, 1475, 200, 200, 950, 950, 950
};
int pausDurations6[] = {
  50, 50, 50, 0, 50, 50, 50, 50, 0, 50, 50, 50, 50, 0, 50, 50, 
  0, 50, 50, 0, 50, 50, 50, 50, 50, 50
};


int melody7[] = {//Für Elise (Beethoven)
  330, 311, 330, 311, 330, 246, 294, 261, 220, 130, 330, 220, 246, 330, 208, 246, 261, 330, 311, 
  330, 311, 330, 246, 294, 261, 220, 130, 330, 220, 246, 261, 246, 220
};
int noteDurations7[] = {
  171, 171, 171, 171, 171, 171, 171, 171, 632, 171, 171, 171, 491, 171, 171, 171, 391, 
  171, 171, 171, 171, 171, 171, 171, 171, 632, 171, 171, 171, 491, 171, 171, 391
};
int pausDurations7[] = { 100,
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 150, 50, 50, 50, 491, 
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 150, 50, 50, 50
};


int melody8[] = { //Hes the Pirat (Fluch der Karribik)
  220, 261, 293, 293, 293, 329, 349, 349, 349, 392, 329, 329, 293, 261, 261, 293, 
  220, 261, 293, 293, 293, 329, 349, 349, 349, 392, 329, 329, 293, 261, 293
};

int noteDurations8[] = { 
  200, 200, 450, 450, 200, 200, 450, 450, 200, 200, 450, 450, 
  200, 200, 200, 450, 200, 200, 450, 450, 200, 200, 450, 450, 
  200, 200, 450, 450, 200, 200, 700
};

int pausDurations8[] = {
  100, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 
  50, 50, 50, 250, 50, 50, 50, 50, 50, 50, 50, 50, 
  50, 50, 50, 50, 50, 50, 50
};


int melody9[] = {
};
int noteDurations9[] = {
};
int pausDurations9[] = {
};


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
  int helligkeit=20;
  digitalWrite(ledPlayPause, HIGH);
    while (true) 
    {
      helligkeit += 20;
      if (helligkeit>255){
        helligkeit=20;
      }
      analogWrite(ledPlayPause, helligkeit);
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
  if(a>maxLieder)   //setzt a
  {
    a = 0;
    ledLichtZaehler = 0;
  }
  else if(a<0)   //setzt a
  {
    a = maxLieder;
    ledLichtZaehler = maxLieder;
  }
  digitalWrite(led3, (a & 8));    //prüft, ob a im 4ten bit = 1 ist (8=2^3=4.bit)
  digitalWrite(led2, (a & 4));
  digitalWrite(led1, (a & 2));
  digitalWrite(led0, (a & 1));
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
  delay (50);
  for (int curentNote = 0; curentNote < sizeof(melody2) / sizeof(melody2[0]); curentNote++)
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
  delay (50);
for (int curentNote = 0; curentNote < sizeof(melody4) / sizeof(melody4[0]); curentNote++)
  {
    butStatPlayPause = !digitalRead(butPlayPause);
    butStatBreak = !digitalRead(butBreak);
    delay(50);

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
  butStatPlayPause = !digitalRead(butPlayPause);
  if (butStatPlayPause)
  {
    if (b==1)
    {
    b=2;
    }else {
      b=1;
      }
  }
  
  if (butStatLinksUp)
  {
    ledLichtZaehler = ledLichtZaehler + b;
    ledlichter(ledLichtZaehler);
  }

  if (butStatRechtsDown)
  {
    ledLichtZaehler = ledLichtZaehler - b;
    ledlichter(ledLichtZaehler);
  }

  if (butStatStart && ledLichtZaehler>0)
  {
    playSong(ledLichtZaehler);
  }
  delay(300);
  loop();
}
