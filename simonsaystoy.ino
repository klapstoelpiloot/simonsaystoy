#include <Wire.h>
#include "simonsaystoy.h"
#include "SoundsEffects.h"
#include "PlaybackState.h"

// Global objects
Speaker speaker;
Seeed_Digital_Tube display;
Button buttons[NUM_BUTTONS];
LED leds[NUM_BUTTONS];
int sequence_length;
int sequence[MAX_SEQUENCE_LENGTH];
IState* currentstate = nullptr;
PlaybackState playbackstate;

// LED toggle sounds
ToggleSound0 togglesound0;
ToggleSound1 togglesound1;
ToneRed tonered;

void setup()
{
    // Setup
    Wire.begin();
    display.setTubeType(TYPE_2, TYPE_2_DEFAULT_I2C_ADDR);
    display.setBrightness(15);
    display.setBlinkRate(BLINK_OFF);
    display.displayNum(0, 0);
    speaker.Init(PIN_SPEAKER);
    buttons[0].Init(PIN_BUTTON_RED);
    buttons[1].Init(PIN_BUTTON_GREEN);
    buttons[2].Init(PIN_BUTTON_BLUE);
    buttons[3].Init(PIN_BUTTON_YELLOW);
    leds[0].Init(PIN_LED_RED);
    leds[1].Init(PIN_LED_GREEN);
    leds[2].Init(PIN_LED_BLUE);
    leds[3].Init(PIN_LED_YELLOW);

    // We may need this for debugging
    Serial.begin(9600);

    // Initialize random numbers
    randomSeed(analogRead(PIN_UNCONNECTED));

    // Test
    speaker.Play(tonered);

    StartPlaybackState();
}

void loop()
{
    speaker.Update();

    // Do the button logic and let the running state know of any button presses
    for(int i = 0; i < NUM_BUTTONS; i++)
    {
      buttons[i].Update();
      if(buttons[i].IsPressed())
      {
          currentstate->OnButtonPress(i);
      }
      else if(buttons[i].IsReleased())
      {
          currentstate->OnButtonRelease(i);
      }
    }

    currentstate->Update();
}

// Generic state changing logic
void ChangeState(IState* newstate)
{
  if(currentstate != nullptr)
  {
    currentstate->Leave();
  }

  currentstate = newstate;

  if(currentstate != nullptr)
  {
    currentstate->Enter();
  }
}

// Accessible methods for states to change to another state
void StartPlaybackState() { ChangeState(&playbackstate); }
