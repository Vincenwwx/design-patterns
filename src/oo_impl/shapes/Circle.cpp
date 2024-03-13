#include "oo_impl/shapes/Circle.h"
#include "oo_impl/ShapeVisitor.h"

namespace oo_impl
{
void Circle::accept(oo_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace oo_impl
