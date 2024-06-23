#pragma once
#include "Button.h"
#include "LED.h"
#include "Speaker.h"
#include "IState.h"
#include "grove_alphanumeric_display.h"

class ToggleSound0;
class ToggleSound1;
class ToneRed;

// Globally accessible objects
extern Speaker speaker;
extern Seeed_Digital_Tube display;
extern Button buttons[NUM_BUTTONS];
extern LED leds[NUM_BUTTONS];
extern int sequence_length;
extern int sequence[MAX_SEQUENCE_LENGTH];

// Accessible methods for states to change to another state
void StartPlaybackState();
