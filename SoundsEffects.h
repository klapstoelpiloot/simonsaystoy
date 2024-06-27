#include "IMelody.h"

class ToggleSound0 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 10; }
    virtual int GetNotePause() override { return 1; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

// ========================================================================================================

class ToggleSound1 : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 10; }
    virtual int GetNotePause() override { return 1; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

// ========================================================================================================

class SoundRed : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 1; }
    virtual int GetNotePause() override { return 1; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

// ========================================================================================================

class SoundGreen : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 1; }
    virtual int GetNotePause() override { return 1; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

// ========================================================================================================

class SoundBlue : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 1; }
    virtual int GetNotePause() override { return 1; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

// ========================================================================================================

class SoundYellow : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 1; }
    virtual int GetNotePause() override { return 1; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

// ========================================================================================================

class RewardSound : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 9; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

// ========================================================================================================

class FailureSound : public virtual IMelody
{
    virtual Note GetNote(int index) override { return Note(notes[index], durations[index]); }
    virtual int GetNoteCount() override { return notecount; }
    virtual int GetTempo() override { return 10; }
    virtual int GetNotePause() override { return 0; }
    virtual bool GetAbsDurations() override { return true; }
    static int notes[];
    static int durations[];
    static int notecount;
};

