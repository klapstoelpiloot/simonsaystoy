#include "RewardState.h"

#define BREAK_DURATION  400

RewardState::RewardState()
{
    nextstatetime = 0;
}

void RewardState::Enter()
{
    Serial.println("Entering RewardState");
    speaker.Stop();
    delay(200);
    display.displayNum(sequence_length, 0);
    speaker.Play(rewardsound);
    nextstatetime = 0;
}

void RewardState::Leave()
{
    Serial.println("Leaving RewardState");
}

void RewardState::Update()
{
    unsigned long t = millis();
    if((nextstatetime > 0) && (t > nextstatetime))
    {
        StartPlaybackState();
    }
    else if((nextstatetime == 0) && speaker.IsFinished())
    {
        nextstatetime = t + BREAK_DURATION;
    }
}

void RewardState::OnButtonPress(int index)
{
}

void RewardState::OnButtonRelease(int index)
{
}
