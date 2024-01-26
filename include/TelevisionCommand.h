#pragma once

#include "Command.h"
#include "furnitures/Television.h"

namespace comd
{
class TurnOnTelevision : public Command
{
public:
    TurnOnTelevision(furniture::Television &television) : television_(television) {}

    void execute() override { television_.turnOn(); }
    void back() override { television_.turnOff(); }

private:
    furniture::Television &television_;
};

class TurnOffTelevision : public Command
{
public:
    TurnOffTelevision(furniture::Television &television) : television_(television) {}

    void execute() override { television_.turnOff(); }
    void back() override { television_.turnOn(); }

private:
    furniture::Television &television_;
};
} // namespace comd
