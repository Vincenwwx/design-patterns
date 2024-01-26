#pragma once

#include "Command.h"
#include <array>
#include <memory>
#include <cstdlib>

namespace cust
{
const size_t NUM_COMMANDS{6};

class ControlCenter
{
public:
    ControlCenter() = default;
    ~ControlCenter() = default;

    void setCommand(size_t idx, std::unique_ptr<comd::Command> &&command)
    {
        commands_.at(idx) = std::move(command);
    }

    void executeCommand(size_t idx)
    {
        commands_.at(idx)->execute();
    }

    void undoCommand(size_t idx)
    {
        commands_.at(idx)->back();
    }

private:
    std::array<std::unique_ptr<comd::Command>, NUM_COMMANDS> commands_;
}; 
} // namespace cust
