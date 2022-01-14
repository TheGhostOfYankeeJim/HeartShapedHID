/*********************************************
* Heart Shaped Music Box
* TheGhostOfYankeeJim 
*
* Circuit: 
* Passive buzzer on digital pin 8, you can 
* use any pin that has a PWM capabilities
* to emulate an AC current with DC.
*
* This code hows how you can create a USB
* rubber ducky like device to perform HID
* attacks. 
*********************************************/

// this is a command to include arduinos keyboard emulator libary
#include <Keyboard.h>

// I was going to do my own pitches, realized arduino has a pitches libary already
#include "pitches.h"

// this is a command to include arduinos Humand Interface Device libary
#include "HID.h"


// notes in the 1000 miles song
// I could of broken up the sections to be more readable
int melody[] = {
  NOTE_B6, NOTE_B7, NOTE_B6, NOTE_AS7, NOTE_B6, NOTE_FS7, NOTE_B6, NOTE_DS7, NOTE_CS7, NOTE_B6, NOTE_B6, NOTE_B7, NOTE_B6, NOTE_AS7, NOTE_B6, NOTE_FS7, NOTE_B6, NOTE_FS7, NOTE_B6, NOTE_DS7, NOTE_E7, NOTE_DS7, NOTE_B6, NOTE_B6, NOTE_B7, NOTE_B6, NOTE_AS7, NOTE_B6, NOTE_FS7, NOTE_B6, NOTE_DS7, NOTE_CS7, NOTE_B6,
  NOTE_DS7, NOTE_CS7, NOTE_B6,
  NOTE_DS7, NOTE_CS7, NOTE_B6,
  NOTE_FS7, NOTE_CS7, NOTE_B6
};

// 2 is a half note, 4 is a quarter note, 8 is a eighth note, I can play piano so this was fairly easy to figure out
int noteLength[] = {
  8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 4, 8, 8, 8, 8, 
  8,8,8,
  8,8,8,
  4,2,2
};


// Quick tests
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

// this will execute first, then go and play the song
void setup()
{
  // this tells to start up the keyboard
  Keyboard.begin();

  // Start Payload, wait 3 seconds
  delay(3000);

  // this brings up the run command on windows
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();

  // wait half a second
  delay(500);

  // keyboard prints the string notepad
  Keyboard.print("notepad");

  // wait half a second
  delay(500);

  // keyboard hits enter, which enter the string
  typeKey(KEY_RETURN);

  // waits a little bit longer to have the notepad application open up
  delay(750);

  // the keyboard prints into the txt doc the string below
  Keyboard.print("You've been hacked!");

  // new line
  typeKey(KEY_RETURN);

  // keyboard enters the string below
  Keyboard.print("From: TheGhostOfYankeeJim");

  // new line
  typeKey(KEY_RETURN);

  // Stop Keyboard emulation
  Keyboard.end();

  
  // this starts the song, convices user nothing is wrong
  for (int currentNote = 0; currentNote < 42; currentNote++) 
  
  {
    // to slow down the pace, I had to play with the noteDuration numbers
    // the larger the number the slower the song plays
    int noteLength = 1250 / noteLength[currentNote];
    
    // arduinos tone function, uses pin 8, takes current note, and plays it for the note duration
    tone(8, melody[currentNote], noteLength);

    // to keep the notes from mushing up togather... we add a no tone or no sound between the notes
    // the pause is 1.3 times by the note duration
    int pauseBetweenNotes = noteLength * 1.30;
    delay(pauseBetweenNotes);
    // kill the tone on pin 8
    noTone(8); 

  }
  
}

// Unused, typical in arduino code
void loop() {}