#pragma once

#include <cstdlib>

namespace furniture
{
class Television
{
public:
    bool isOn() const { return is_on_; }
    void turnOn() { is_on_ = true; }
    void turnOff() { is_on_ = false; }

    size_t channelNum() const { return channel_num_; }
    void turnNextChannel()
    {
        if(++channel_num_ == MAX_CHANNEL_NUM)
        {
            channel_num_ = 0;
        }
    }

    void printStatus() const
    {
        std::cout << "Television\n----------\n- on: " << is_on_ << "\n- Channel: " 
            << channel_num_ << '\n';
    }

private:
    bool is_on_{false};
    size_t channel_num_{0};

    static constexpr size_t MAX_CHANNEL_NUM{35};
};

} // namespace furniture
