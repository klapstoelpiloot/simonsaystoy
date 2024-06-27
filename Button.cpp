#include "Button.h"

#define DEBOUNCE_TIMEOUT    50

// Constructor
Button::Button()
{
    pin = 0;
    changetime = 0;
    laststate = false;
    down = false;
    pressed = false;
    released = false;
}

// Destructor
Button::~Button()
{
}

void Button::Init(int buttonpin)
{
	pin = buttonpin;
	pinMode(pin, INPUT_PULLUP);
}

void Button::Update()
{
    unsigned long t = millis();

    // See if the pin state changed
    bool pinstate = (digitalRead(pin) == LOW);
    if(pinstate != laststate)
    {
        laststate = pinstate;
        changetime = t;
    }

    pressed = false;
    released = false;

    // Debounce and update state
    if((laststate != down) && ((t - changetime) > DEBOUNCE_TIMEOUT))
    {
        down = laststate;

        if(laststate)
            pressed = true;
        else
            released = true;
    }
}
