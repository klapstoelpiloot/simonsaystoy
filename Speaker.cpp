#include "Arduino.h"
#include "Speaker.h"

Speaker::Speaker() :
    pin(0),
    melody(nullptr),
    currentnote(-1),
    nextnotetime(0),
    wholenoteduration(0)
{
}

void Speaker::Init(int speakerpin)
{
    pin = speakerpin;
}

void Speaker::Update()
{
    if((melody != nullptr) && (millis() >= nextnotetime))
    {
        PlayNextNote();
    }
}

void Speaker::Play(IMelody& m)
{
    noTone(pin);
    melody = &m;
    wholenoteduration = (60000 * 4) / melody->GetTempo();
    currentnote = -1;
    PlayNextNote();
}

void Speaker::Stop()
{
    noTone(pin);
    melody = nullptr;
    currentnote = -1;
}

void Speaker::PlayNextNote()
{
    currentnote++;
    if(currentnote >= melody->GetNoteCount())
    {
        Stop();
        return;
    }

    // Setup note
    Note n = melody->GetNote(currentnote);
    int toneduration;
    int pauseduration;
    if(melody->GetAbsDurations())
    {
        toneduration = n.Duration / melody->GetTempo();
        pauseduration = melody->GetNotePause() / melody->GetTempo();
    }
    else
    {
        toneduration = wholenoteduration / n.Duration;
        pauseduration = (melody->GetNotePause() > 0) ? (wholenoteduration / melody->GetNotePause()) : 0;
    }

    // Play the note
    if(n.Tone != REST)
    {
        tone(pin, n.Tone, toneduration);
    }
    else
    {
        noTone(pin);
    }

    nextnotetime = millis() + toneduration + pauseduration;
}
