#pragma once

#include "inh_impl/shapes/Circle.h"
#include "inh_impl/shapes/Square.h"

namespace inh_impl
{
class ShapeVisitor
{
public:
    virtual ~ShapeVisitor() = default;

    virtual void visit(Circle const &circle) const = 0;
    virtual void visit(Square const &square) const = 0;
};
}  // namespace inh_impl
