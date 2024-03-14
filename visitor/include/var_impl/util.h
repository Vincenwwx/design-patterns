#pragma once

#include "var_impl/Draw.h"
#include "var_impl/shapes/Shape.h"

namespace var_impl
{
void drawAllShapes(Shapes const &shapes)
{
    for (auto const &shape : shapes)
    {
        std::visit(Draw{}, shape);
    }
}

}  // namespace var_impl
