#include "Circle.h"
#include "ShapeVisitor.h"

namespace object
{
void Circle::accept(oo_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace object
