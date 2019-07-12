#pragma once

struct RegisteredKeyState
{
    bool pressedW;
    bool pressedS;
    bool pressedA;
    bool pressedD;
};

class InputObserver
{
public:
    virtual ~InputObserver() = default;
    virtual void inputChanged(const RegisteredKeyState&) = 0;
};
