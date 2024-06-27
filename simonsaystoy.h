#pragma once
#include "Button.h"
#include "LED.h"
#include "Speaker.h"
#include "IState.h"
#include "SoundsEffects.h"
#include "grove_alphanumeric_display.h"

// Globally accessible objects
extern Speaker speaker;
extern Seeed_Digital_Tube display;
extern Button buttons[NUM_BUTTONS];
extern LED leds[NUM_BUTTONS];
extern int sequence_length;
extern int sequence[MAX_SEQUENCE_LENGTH];
extern IMelody* ledsounds[NUM_BUTTONS];
extern RewardSound rewardsound;
extern FailureSound failsound;

// Accessible methods for states to change to another state
void StartPlaybackState();
void StartInputState();
void StartFailedState();
void StartRewardState();
