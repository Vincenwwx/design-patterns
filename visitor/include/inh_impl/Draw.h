#pragma once

#include "ShapeVisitor.h"

#include <iostream>

namespace inh_impl
{
class Draw : public ShapeVisitor
{
public:
    void visit(Circle const &circle) const override { std::cout << "Draw circle" << std::endl; }

    void visit(Square const &square) const override { std::cout << "Draw square" << std::endl; }
};

}  // namespace inh_impl
