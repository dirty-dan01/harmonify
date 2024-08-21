#include "chords.h"
#include "scales.h"
#include "midi.h"
#include "octave.h"


// Genera un acorde de triada
void generateTriad(int* scale, int degree, int* chord) {
    chord[0] = scale[degree % SCALE_LENGTH];
    chord[1] = scale[(degree + 2) % SCALE_LENGTH];
    chord[2] = scale[(degree + 4) % SCALE_LENGTH];
}

// Genera un acorde de séptima
void generateSeventhChord(int* scale, int degree, int* chord) {
    chord[0] = scale[degree % SCALE_LENGTH];
    chord[1] = scale[(degree + 2) % SCALE_LENGTH];
    chord[2] = scale[(degree + 4) % SCALE_LENGTH];
    chord[3] = scale[(degree + 6) % SCALE_LENGTH];
}

void initChords() {
    // Inicializa cualquier configuración de acordes
}

void handleChords() {
    Serial.println("Iniciando manejo de acordes");
    Serial.print("Nota raíz: ");
    Serial.println(rootNote);

    sendNoteOn(rootNote, 127);
    // Ejemplo de acorde mayor simple
    sendNoteOn(rootNote, 127);   // Nota raíz
    sendNoteOn(rootNote + 4, 127); // Tercera mayor
    sendNoteOn(rootNote + 7, 127); // Quinta justa
}
