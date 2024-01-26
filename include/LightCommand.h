#pragma once

#include "Command.h"

namespace comd
{
class TurnOnLight : public Command
{
public:
    TurnOnLight(furniture::Light &light) : light_(light) {}

    void execute() override { light_.turnOn(); }
    void back() override { light_.turnOff(); }

private:
    furniture::Light &light_;
};

class TurnOffLight : public Command
{
public:
    TurnOffLight(furniture::Light &light) : light_(light) {}

    void execute() override { light_.turnOff(); }
    void back() override { light_.turnOn(); }

private:
    furniture::Light &light_;
};

class MakeRoomWarmer : public Command
{
public:
    MakeRoomWarmer(furniture::Light &light) : light_(light) {}

    void execute() override;
    void back() override;

private:
    furniture::Light &light_;
};

} // namespace comd
