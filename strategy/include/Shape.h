#pragma once

namespace strategy
{
class Shape
{
public:
    virtual ~Shape() = default;

    virtual void draw() const = 0;
};

} // namespace strategy
