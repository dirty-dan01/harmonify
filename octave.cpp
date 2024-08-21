#include "octave.h"
#include "Arduino.h"
#include "midi.h"

const int PIN_BUTTON1Oct = 22;
const int PIN_BUTTON2Oct = 21;

byte rootNote = 60;

int currentOctave = 0;

void initOctave() {
    pinMode(PIN_BUTTON1Oct, INPUT);
    pinMode(PIN_BUTTON2Oct, INPUT);
}

void handleOctave() {
    int octaveUp = digitalRead(PIN_BUTTON1Oct);
    int octaveDown = digitalRead(PIN_BUTTON2Oct);
    
    if (octaveUp == HIGH) {
        currentOctave++;
        rootNote += 12; // Sube una octava
    }
    if (octaveDown == HIGH) {
        currentOctave--;
        rootNote -= 12; // Baja una octava
    }
}
