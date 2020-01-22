#include "Keyboard.h"

const int profilesKey = 15;

const int boardKey1 = 2;
const int boardKey2 = 3;

const int blueKey1 = 5;
const int blueKey2 = 6;
const int blueKey3 = 4;

const int Led1 = 9;
const int Led2 = 10;

bool bkey1 = true;
bool bkey2 = true;

bool ledFade = true;
bool ledFadeUP = true;
int fadeDelay = 10;
int fadeIndex = 0;
unsigned long previousMillis = 0;

int currentProfile = 0;

void setup() {
  pinMode(profilesKey, INPUT_PULLUP); 
  pinMode(boardKey1, INPUT_PULLUP);
  pinMode(boardKey2, INPUT_PULLUP);
  pinMode(blueKey1, INPUT_PULLUP);
  pinMode(blueKey2, INPUT_PULLUP);
  pinMode(blueKey3, INPUT_PULLUP);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  Keyboard.begin();
  previousMillis = 0;
}
void loop() {
  if(ledFade)   
    {
      if(millis() - previousMillis > fadeDelay){
        previousMillis = millis(); 
        if(ledFadeUP){
        if(fadeIndex<255 && ledFadeUP){
          analogWrite(Led1, fadeIndex);
          analogWrite(Led2, fadeIndex);
          fadeIndex++;
        }
        else{
          ledFadeUP=false;
        }
        }
        else{
        if(fadeIndex>1){
          analogWrite(Led1, fadeIndex);
          analogWrite(Led2, fadeIndex);
          fadeIndex--;
        }
        else{
          ledFadeUP=true;
        }
        }
      }
    }
  
  if(digitalRead(profilesKey)==LOW){
    ledFade = false;
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    if(currentProfile+1>2){
      currentProfile=0;
      bkey1 = true; 
      bkey2 = true;
    }
    else{
      currentProfile++;
    }
    delay(300);
  }
  
  if(currentProfile==0){
    
    if(digitalRead(boardKey1)==LOW){
      if(bkey1){
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('C');
        delay(10);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release('C');
      }
      bkey1 = false;
    }
    else{
      bkey1 = true;
    }
    
    if(digitalRead(boardKey2)==LOW){
      if(bkey2){
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('V');
        //delay(10);
        Keyboard.release(KEY_LEFT_CTRL);
        Keyboard.release('V');
      }
      bkey2 = false;
    }
    else{
      bkey2 = true;
    }
    
    if(digitalRead(blueKey1)==LOW){
      Keyboard.press(' ');
    }
    else{
      Keyboard.release(' ');
    }
    
    if(digitalRead(blueKey2)==LOW){
      Keyboard.press('\n');
    }
    else{
      Keyboard.release('\n');
    }
    
    if(digitalRead(blueKey3)==LOW){
      Keyboard.press(KEY_BACKSPACE);
    }
    else{
      Keyboard.release(KEY_BACKSPACE);
    }
  }
  else if(currentProfile==1){
    
    digitalWrite(Led1, HIGH);
  
    if(digitalRead(boardKey1)==LOW){
      Keyboard.press('M');
    }
    else{
      Keyboard.release('M');
    }
 
    if(digitalRead(boardKey2)==LOW){
      Keyboard.press('N');
    }
    else{
      Keyboard.release('N');
    }
    
    if(digitalRead(blueKey1)==LOW){
      Keyboard.press(KEY_RIGHT_ALT);
    }
    else{
      Keyboard.release(KEY_RIGHT_ALT);
    }
    
    if(digitalRead(blueKey2)==LOW){
      Keyboard.press(' ');
    }
    else{
      Keyboard.release(' ');
    }
  
    if(digitalRead(blueKey3)==LOW){
      Keyboard.press(KEY_ESC);
    }
    else{
      Keyboard.release(KEY_ESC);
    }
  }
  //if isn't necessary if profile 2(3) is last
  else if(currentProfile==2){
    digitalWrite(Led2, HIGH);
    //CS or other profile
  }
}
