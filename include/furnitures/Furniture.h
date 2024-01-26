#pragma once

namespace furniture
{
class Furniture
{
public:
    Furniture() = default;
    virtual ~Furniture() = default;

    virtual void printStatus() const = 0;
};

} // namespace furniture
