#include "buttons.h"
#include "Arduino.h"
#include "midi.h" // Para enviar mensajes MIDI

const int buttonPin = 2;
int buttonState = 0;
int buttonPState = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

void initButtons() {
    pinMode(buttonPin, INPUT);
}

void handleButtons() {
    int reading = digitalRead(buttonPin);
    if (reading != buttonPState) {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == HIGH) {
                // Envía una nota MIDI o realiza otra acción
                sendNoteOn(60, 127); // Ejemplo: Nota C4, velocidad 127
            }
        }
    }
    buttonPState = reading;
}
