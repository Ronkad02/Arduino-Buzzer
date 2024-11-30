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
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 200,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50
};

//Hier sollen die Arrays hin für Melody und Duration und Pausendealay
//oder Melody und Duration und Duration verzweifachen und doppelt durch gehen(einmal mit Melody und einmal mit pausen aka Melodyduration, Pausenduration, Melodyduration,...)

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



void playSong (int a)
{
bool paus=0;

switch (a)
{
  case 1:
  {
    
    for (int curentNote = 0; curentNote < sizeof(melody1) / sizeof(melody1[0]); curentNote++)
    {
        int noteDuration = noteDurations1[curentNote];
        int pauseDuration = pausDurations1[curentNote];
        tone(buzzer1, melody1[curentNote]);
        delay(noteDuration);

        noTone(buzzer1);
        delay(pauseDuration);

    }

break;
}
/*case 2:

break;
case 3:

break;
case 4:

break;
case 5:

break;
case 6:

break;
case 7:

break;
case 8:

break;
case 9:

break;
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
