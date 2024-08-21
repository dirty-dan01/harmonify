#include "potentiometers.h"
#include "buttons.h"
#include "midi.h"
#include "chords.h"
#include "octave.h"
#include <Arduino.h>
#include "scales.h"

bool isMajor = true;
int scale[SCALE_LENGTH];
int chord[4]; // Acorde con espacio para una séptima

void setup() {
    Serial.begin(9600);
    initPotentiometers();
    initButtons();
    initMIDI();
    initChords();
    initOctave();
    if (isMajor) {
        generateMajorScale(rootNote, scale);
    } else {
        generateMinorScale(rootNote, scale);
    }

    // Genera un acorde de triada en el grado I
    generateTriad(scale, 0, chord);
    Serial.println("Triad: ");
    for (int i = 0; i < 3; i++) {
        Serial.println(chord[i]);
    }

    // Genera un acorde de séptima en el grado V
    generateSeventhChord(scale, 4, chord);
    Serial.println("Seventh Chord: ");
    for (int i = 0; i < 4; i++) {
        Serial.println(chord[i]);
    }
}

void loop() {
    readPotentiometers();
    handleButtons();
    sendMIDI();
    handleChords();
    handleOctave();
}

