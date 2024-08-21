#include "midi.h"
#include "MIDIUSB.h"

void initMIDI() {
    // Inicializa cualquier configuración MIDI necesaria
}

void sendMIDI() {
    // Procesa y envía mensajes MIDI
    MidiUSB.flush();
}

void sendNoteOn(byte pitch, byte velocity) {
    midiEventPacket_t noteOn = {0x09, 0x90, pitch, velocity};
    MidiUSB.sendMIDI(noteOn);
}

void sendNoteOff(byte pitch, byte velocity) {
    midiEventPacket_t noteOff = {0x08, 0x80, pitch, velocity};
    MidiUSB.sendMIDI(noteOff);
}

void sendControlChange(byte control, byte value) {
    midiEventPacket_t controlChange = {0x0B, 0xB0, control, value};
    MidiUSB.sendMIDI(controlChange);
}
