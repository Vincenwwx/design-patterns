#include "furnitures/Light.h"
#include "furnitures/Television.h"
#include "LightCommand.h"
#include "TelevisionCommand.h"
#include "ControlCenter.h"
#include <memory>
#include <ranges>

int main()
{
    auto light = std::make_shared<furniture::Light>();
    auto television = std::make_shared<furniture::Television>();
    std::vector<std::shared_ptr<furniture::Furniture>> monitor{light, television};

    cust::ControlCenter control{};
    control.setCommand(0, std::make_unique<comd::TurnOnLight>(*light));
    control.setCommand(1, std::make_unique<comd::TurnOnTelevision>(*television));

    control.executeCommand(0);
    std::ranges::for_each(monitor, &furniture::Furniture::printStatus);

    control.executeCommand(1);
    std::ranges::for_each(monitor, &furniture::Furniture::printStatus);

    return 0;
}