#include "Keyboard.h"

const int profilesKey = 15;
const int boardKey1 = 2;
const int boardKey2 = 3;
const int blueKey1 = 5;
const int blueKey2 = 6;
const int blueKey3 = 4;

int boardKey1_PreviousState;
int boardKey2_PreviousState;

int currentProfile = 0;

void setup() {
  pinMode(profilesKey, INPUT_PULLUP); 
  pinMode(boardKey1, INPUT_PULLUP);
  pinMode(boardKey2, INPUT_PULLUP);
  pinMode(blueKey1, INPUT_PULLUP);
  pinMode(blueKey2, INPUT_PULLUP);
  pinMode(blueKey3, INPUT_PULLUP);
  Keyboard.begin();
  boardKey1_PreviousState = digitalRead(boardKey1);
  boardKey2_PreviousState = digitalRead(boardKey2);
}

void loop() {
 int boardKey1_State = digitalRead(boardKey1);
 int boardKey2_State = digitalRead(boardKey2);

  if(digitalRead(profilesKey)==LOW){
    if(currentProfile+1>2){
      currentProfile=0;
    }
    else{
      currentProfile++;
    }
    delay(300);
  }
 if(currentProfile==1){
   if(boardKey1_PreviousState != boardKey1_State){
    Keyboard.press('M');
    }
   else{
    Keyboard.release('M');
    }
 
  if(boardKey2_PreviousState != boardKey2_State){
    Keyboard.press('N');
  }
  else{
    Keyboard.release('N');
  }
  
  if(digitalRead(blueKey1)==LOW){
    Keyboard.press(KEY_RIGHT_ALT);
    delay(150);
    Keyboard.release(KEY_RIGHT_ALT);
    delay(10);
  }
  
  if(digitalRead(blueKey2)==LOW){
    Keyboard.print(' ');
    delay(250);
  }
  
  if(digitalRead(blueKey3)==LOW){
    Keyboard.press(KEY_ESC);
    Keyboard.release(KEY_ESC);
    delay(250);
  }
  
 }
}
