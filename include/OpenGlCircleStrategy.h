#pragma once

#include "DrawStrategy.h"
#include <iostream>

namespace strategy
{
class Circle;

class OpenGlCircleStrategy : public DrawStrategy<Circle>
{
public:
    void draw(const Circle &obj) const override
    {
        std::cout << "Draw circle using OpenGL strategy" << std::endl;
    }
};

} // namespace strategy
