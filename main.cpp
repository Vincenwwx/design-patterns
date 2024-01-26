#include "furnitures/Light.h"
#include "furnitures/Television.h"
#include "LightCommand.h"
#include "TelevisionCommand.h"
#include "ControlCenter.h"
#include <memory>

int main()
{
    furniture::Light light{};
    furniture::Television television{};

    cust::ControlCenter control{};
    control.setCommand(0, std::make_unique<comd::TurnOnLight>(light));
    control.setCommand(1, std::make_unique<comd::TurnOnTelevision>(television));

    control.executeCommand(0);
    light.printStatus();
    television.printStatus();

    control.executeCommand(1);
    light.printStatus();
    television.printStatus();

    return 0;
}