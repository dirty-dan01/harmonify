#ifndef MIDI_H
#define MIDI_H

#include <Arduino.h>

void initMIDI();
void sendMIDI();
void sendNoteOn(byte pitch, byte velocity);
void sendNoteOff(byte pitch, byte velocity);
void sendControlChange(byte control, byte value);

#endif
