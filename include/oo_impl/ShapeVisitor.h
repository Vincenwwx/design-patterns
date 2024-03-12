#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

namespace oo_impl
{
class ShapeVisitor
{
public:
    virtual ~ShapeVisitor() = default;

    virtual void visit(const object::Circle & circle) const = 0;
    virtual void visit(const object::Square & square) const = 0;
};
} // namespace oo_impl
