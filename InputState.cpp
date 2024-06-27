#include "InputState.h"

#define DOT_FLASH_INTERVAL  200

InputState::InputState()
{
    sequence_position = 0;
}

void InputState::Enter()
{
    Serial.println("Entering InputState");
    sequence_position = 0;
    failed = false;
    display.setPoint(false, true);
    display.display();
}

void InputState::Leave()
{
    Serial.println("Leaving InputState");
}

void InputState::Update()
{
}

void InputState::OnButtonPress(int index)
{
    leds[index].Set(HIGH);
    speaker.Play(*ledsounds[index]);

    if(index == sequence[sequence_position])
    {
        if(sequence_position < sequence_length)
            sequence_position++;
    }
    else
    {
        failed = true;
    }
}

void InputState::OnButtonRelease(int index)
{
    leds[index].Set(LOW);
    speaker.Stop();

    if(failed)
    {
        StartFailedState();
    }
    else if(sequence_position >= sequence_length)
    {
        StartRewardState();
    }
}
