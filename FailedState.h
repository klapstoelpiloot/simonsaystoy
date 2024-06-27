#include "simonsaystoy.h"

class FailedState : public virtual IState
{
private:

public:

    FailedState();

    // Called when entering this state.
    virtual void Enter() override;

    // Called when leaving this state.
    virtual void Leave() override;

    // Called repeatedly to update states.
    virtual void Update() override;

    // Called when one of the buttons is pressed. Not called when a button is held down.
    // To check buttons being held down, use the Buttons object.
    virtual void OnButtonPress(int index) override;

    // Called when one of the buttons is released after being pressed.
    virtual void OnButtonRelease(int index) override;
};
