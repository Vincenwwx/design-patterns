#pragma once

#include "DrawStrategy.h"
// #include "Circle.h"
#include <iostream>

namespace strategy
{
class Circle;

class MetaCircleStrategy : public DrawStrategy<Circle>
{
public:
    void draw(const Circle &obj) const override
    {
        std::cout << "Draw circle using Meta strategy" << std::endl;
    }
};

} // namespace strategy
