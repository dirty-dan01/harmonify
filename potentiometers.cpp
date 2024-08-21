#include "potentiometers.h"
#include "Arduino.h"
#include "midi.h" // Para enviar mensajes MIDI

const int potPin = A0;
const int potPin2 = A1;
const int potPin3 = A2;
const int potPin4 = A3;

int potCC = 11;
int potCC2 = 12;
int potCC3 = 13;
int potCC4 = 14;

int lastPotValue = 0;
int lastPotValue2 = 0;
int lastPotValue3 = 0;
int lastPotValue4 = 0;

const int threshold = 1; // Sensibilidad para el cambio de valor

void initPotentiometers() {
    pinMode(potPin, INPUT);
    pinMode(potPin2, INPUT);
    pinMode(potPin3, INPUT);
    pinMode(potPin4, INPUT);
}

void readPotentiometers() {
    int potValue = analogRead(potPin) >> 3;
    int potValue2 = analogRead(potPin2) >> 3;
    int potValue3 = analogRead(potPin3) >> 3;
    int potValue4 = analogRead(potPin4) >> 3;

    if (abs(potValue - lastPotValue) > threshold) {
        sendControlChange(potCC, potValue);
        lastPotValue = potValue;
    }
    if (abs(potValue2 - lastPotValue2) > threshold) {
        sendControlChange(potCC2, potValue2);
        lastPotValue2 = potValue2;
    }
    if (abs(potValue3 - lastPotValue3) > threshold) {
        sendControlChange(potCC3, potValue3);
        lastPotValue3 = potValue3;
    }
    if (abs(potValue4 - lastPotValue4) > threshold) {
        sendControlChange(potCC4, potValue4);
        lastPotValue4 = potValue4;
    }
}
