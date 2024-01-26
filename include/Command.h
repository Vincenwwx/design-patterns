#pragma once

#include "furnitures/Light.h"
#include "furnitures/Television.h"

namespace comd
{
class Command
{
public:
    Command() = default;
    virtual ~Command() = default;

    virtual void execute() = 0;
    virtual void back() = 0;
};

} // namespace comd
