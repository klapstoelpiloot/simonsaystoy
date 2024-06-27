#include "PlaybackState.h"

#define BREAK_DURATION      200
#define TOTAL_DURATION      (NOTE_DURATION + BREAK_DURATION)

PlaybackState::PlaybackState()
{
    sequence_position = 0;
    nexttime = 0;
}

void PlaybackState::Enter()
{
    Serial.println("Entering PlaybackState");

    // Add one to the sequence
    sequence[sequence_length] = (int)random(0, NUM_BUTTONS);
    sequence_length++;

    // Playback from begin
    sequence_position = -1;
    nexttime = 0;
}

void PlaybackState::Leave()
{
    Serial.println("Leaving PlaybackState");
}

void PlaybackState::Update()
{
    unsigned long t = millis();

    if(t >= nexttime)
    {
        sequence_position++;
        if(sequence_position >= sequence_length)
        {
            // End of playback, allow user input
            StartInputState();
        }
        else
        {
            int s = sequence[sequence_position];
            leds[s].Set(HIGH);
            speaker.Play(*ledsounds[s]);
            nexttime = t + TOTAL_DURATION;
        }
    }

    if(t >= (nexttime - BREAK_DURATION))
    {
        for(int i = 0; i < NUM_BUTTONS; i++)
        {
            leds[i].Set(LOW);
        }
    }
}

void PlaybackState::OnButtonPress(int index)
{
}

void PlaybackState::OnButtonRelease(int index)
{
}
