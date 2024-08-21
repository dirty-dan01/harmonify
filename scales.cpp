#include "scales.h"

// Genera la escala mayor
void generateMajorScale(int rootNote, int* scale) {
    int majorIntervals[] = {2, 2, 1, 2, 2, 2, 1};
    scale[0] = rootNote;
    for (int i = 1; i < SCALE_LENGTH; i++) {
        scale[i] = scale[i - 1] + majorIntervals[i - 1];
    }
}

// Genera la escala menor
void generateMinorScale(int rootNote, int* scale) {
    int minorIntervals[] = {2, 1, 2, 2, 1, 2, 2};
    scale[0] = rootNote;
    for (int i = 1; i < SCALE_LENGTH; i++) {
        scale[i] = scale[i - 1] + minorIntervals[i - 1];
    }
}
