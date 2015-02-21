// ---------------------------------------------------------------------------
//
// FifteenStep.h
// A generic MIDI sequencer library for Arduino.
//
// Author: Todd Treece <todd@uniontownlabs.org>
// Copyright: (c) 2015 Adafruit Industries
// License: GNU GPLv3
//
// ---------------------------------------------------------------------------
#ifndef _FifteenStep_h
#define _FifteenStep_h

#include "Arduino.h"
#include "FifteenStepNote.h"

#define FS_DEFAULT_TEMPO 120
#define FS_DEFAULT_STEPS 16

typedef void (*MIDIcallback) (byte command, byte arg1, byte arg2);
typedef void (*StepCallback) (int current, int last);

class FifteenStep
{
  public:
    FifteenStep();
    void  begin();
    void  begin(int tempo);
    void  begin(int tempo, int steps);
    void  run();
    void  setTempo(int tempo);
    void  setSteps(int steps);
    void  increaseShuffle();
    void  decreaseShuffle();
    void  setMidiHandler(MIDIcallback cb);
    void  setStepHandler(StepCallback cb);
    void  setNote(bool on, byte pitch, byte velocity);
  private:
    MIDIcallback      _midi_cb;
    StepCallback      _step_cb;
    FifteenStepNote   **_sequence;
    int               _tempo;
    int               _steps;
    int               _position;
    unsigned long     _sixteenth;
    unsigned long     _shuffle;
    unsigned long     _next_beat;
    unsigned long     _shuffleDivision();
    void              _step();
    void              _triggerNotes();
};

#endif
