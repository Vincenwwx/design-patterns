#pragma once

#include "ShapeVisitor.h"

#include <iostream>

namespace oo_impl
{
class Draw : public ShapeVisitor
{
public:
    void visit(Circle const &circle) const override { std::cout << "Draw circle" << std::endl; }

    void visit(Square const &square) const override { std::cout << "Draw square" << std::endl; }
};

}  // namespace oo_impl
