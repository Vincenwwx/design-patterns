#pragma once

#include <iostream>
#include <format>

namespace furniture
{
class Light
{
public:
    Light() = default;
    ~Light() = default;

    void turnOn() { brightness_ = 10; }
    void turnOff() { brightness_ = 0; }

    size_t brightness() const { return brightness_; }
    void setBrightness(size_t brightness)
    {
        brightness_ = brightness > MAX_BRIGHTNESS ? MAX_BRIGHTNESS : brightness;
    }

    int temperature() const { return temperature_; }
    void setTemperature(int temperature) { temperature_ = temperature; }

    void printStatus() const
    {
        std::cout << "Light\n----------\n- brightness: " << brightness_ << "\n- temperature: " 
            << temperature_ << '\n';
    }

private:
    // brightness ranges from 0 to 100 (dark to light).
    size_t brightness_{0};
    int temperature_{0};

    static constexpr size_t MAX_BRIGHTNESS{100};
};

} // namespace furniture
