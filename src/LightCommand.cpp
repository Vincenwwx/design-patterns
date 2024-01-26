#include "LightCommand.h"

namespace comd
{
void MakeRoomWarmer::execute()
{
    auto brightness = light_.brightness();
    if(brightness < 5)
    {
        brightness = 35;
    }
    else
    {
        brightness--;
    }
    light_.setBrightness(brightness);

    auto temperature = light_.temperature();
    temperature += 2;
    light_.setTemperature(temperature);
}

void MakeRoomWarmer::back()
{
    auto brightness = light_.brightness();
    if(brightness == 35)
    {
        brightness = 0;
    }
    else
    {
        brightness++;
    }
    light_.setBrightness(brightness);

    auto temperature = light_.temperature();
    temperature -= 2;
    light_.setTemperature(temperature);
}

} // namespace comd
