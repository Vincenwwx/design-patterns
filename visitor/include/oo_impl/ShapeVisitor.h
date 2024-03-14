#pragma once

#include "oo_impl/shapes/Circle.h"
#include "oo_impl/shapes/Square.h"

namespace oo_impl
{
class ShapeVisitor
{
public:
    virtual ~ShapeVisitor() = default;

    virtual void visit(Circle const &circle) const = 0;
    virtual void visit(Square const &square) const = 0;
};
}  // namespace oo_impl
