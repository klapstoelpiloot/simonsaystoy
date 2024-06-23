#pragma once
#include "Arduino.h"

class Button
{
private:

	// The pin we are monitoring
	int pin;

	// Internals
	unsigned long changetime;
	bool laststate;

  // These are only updated after debouncing/timeout.
  // `down` tells if a button is being held down.
  // `pressed` tells if a button was pressed since last Update()
  // `released` tells if a button was pressed since last Update()
  bool down;
  bool pressed;
  bool released;

public:

	Button();
	virtual ~Button();

	void Init(int buttonpin);
  void Update();
  bool IsDown() { return down; }
	bool IsPressed() { return pressed; }
  bool IsReleased() { return released; }
};
