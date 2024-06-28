#include "SoundsEffects.h"

int ToggleSound0::notes[] = {
    50, 180, 50
};

int ToggleSound0::durations[] = {
    180, 160, 180
};

int ToggleSound0::notecount = sizeof(ToggleSound0::notes) / sizeof(ToggleSound0::notes[0]);

// ========================================================================================================

int ToggleSound1::notes[] = {
    150, REST, 220, REST, 100
};

int ToggleSound1::durations[] = {
    160, 200, 160, 100, 180
};

int ToggleSound1::notecount = sizeof(ToggleSound1::notes) / sizeof(ToggleSound1::notes[0]);

// ========================================================================================================

int SoundRed::notes[] = {
    NOTE_E2
};

int SoundRed::durations[] = {
    300
};

int SoundRed::notecount = sizeof(SoundRed::notes) / sizeof(SoundRed::notes[0]);

// ========================================================================================================

int SoundGreen::notes[] = {
    NOTE_E3
};

int SoundGreen::durations[] = {
    300
};

int SoundGreen::notecount = sizeof(SoundGreen::notes) / sizeof(SoundGreen::notes[0]);

// ========================================================================================================

int SoundBlue::notes[] = {
    NOTE_E4
};

int SoundBlue::durations[] = {
    300
};

int SoundBlue::notecount = sizeof(SoundBlue::notes) / sizeof(SoundBlue::notes[0]);

// ========================================================================================================

int SoundYellow::notes[] = {
    NOTE_E5
};

int SoundYellow::durations[] = {
    300
};

int SoundYellow::notecount = sizeof(SoundYellow::notes) / sizeof(SoundYellow::notes[0]);

// ========================================================================================================

int RewardSound::notes[] = {
    NOTE_GS3, NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4
};

int RewardSound::durations[] = {
    850, 850, 850, 850, 850, 4160
};

int RewardSound::notecount = sizeof(RewardSound::notes) / sizeof(RewardSound::notes[0]);

// ========================================================================================================

int FailureSound::notes[] = {
    NOTE_E4, REST, NOTE_C4, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3
};

int FailureSound::durations[] = {
    2000, 100, 300, 300, 300, 300, 300, 300, 300, 6000
};

int FailureSound::notecount = sizeof(FailureSound::notes) / sizeof(FailureSound::notes[0]);

