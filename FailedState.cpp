#include "FailedState.h"

FailedState::FailedState()
{
}

void FailedState::Enter()
{
    Serial.println("Entering FailedState");
    speaker.Stop();
    delay(200);
    display.displayNum(sequence_length - 1, 0);
    speaker.Play(failsound);
}

void FailedState::Leave()
{
    Serial.println("Leaving FailedState");
}

void FailedState::Update()
{
    unsigned long t = millis();
}

void FailedState::OnButtonPress(int index)
{
}

void FailedState::OnButtonRelease(int index)
{
}
