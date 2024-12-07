#include <EEPROM.h>


unsigned char arr1[] = { 100,   //Pause durration 2 array Leise rieselt der Schnee
  50, 50, 50, 50, 50, 0, 50, 50, 50, 50, 50, 50, 0, 50, 50, 50, 50, 50,
  50, 50, 0, 50, 50, 50, 50, 50, 50, 50, 0, 50
};      //31 Daten hier (Serial monitor, for next array use 31 as i start)

unsigned char arr2[] = { 100,   //Pause duration 8 array Fluch der Karibik
  50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 
  50, 50, 50, 250, 50, 50, 50, 50, 50, 50, 50, 50, 
  50, 50, 50, 50, 50, 50, 50
};  //32 Daten hier ((Serial monitor, for next array use x+32 as i start)

unsigned char arr3[] = { 50, //Pause duratin 6 array a million Dream
  50, 50, 0, 50, 50, 50, 50, 0, 50, 50, 50, 50, 0, 50, 50, 
  0, 50, 50, 0, 50, 50, 50, 50, 50, 50
};  //26 Daten hier ((Serial monitor, for next array use x+26 as i start)

unsigned char arr4[] = { 100, //Pause duration 1 array Happy Birthday
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 200,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50, 50,
  50, 50, 50, 50, 50, 50
};  //51 Daten hier ((Serial monitor, for next array use x+51 as i start)

unsigned char arr5[] = {  //melody array 2 Leise rieselt der Schnee
  220, 220, 196, 220, 196, 174, 174, 174, 146, 174, 164, 146, 130, 130, 196, 184, 196, 246, 220, 196,
  174, 174, 196, 146, 146, 164, 146, 164, 174, 174
};    //30 Daten hier ((Serial monitor, for next array use x+30 as i start)


int x=0+31+32+26+51+30;  //arr Datenzahlen schon geladen bis arr5


void setup() {
  Serial.begin(9600);
  Serial.println(sizeof(arr) / sizeof(arr[0]));
  for(unsigned char i=0+x; i< (sizeof(arr) / sizeof(arr[0]))+x; i++){
    EEPROM.update(i+1, arr[i-x]);
    Serial.print(unsigned(i+1));
    Serial.println(EEPROM.read(i + 1));
  }
}

void loop() {

}
