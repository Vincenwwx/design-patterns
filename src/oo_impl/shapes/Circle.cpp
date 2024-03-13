#include "Circle.h"
#include "ShapeVisitor.h"

namespace oo_impl
{
void Circle::accept(oo_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace oo_impl
