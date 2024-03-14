#include "inh_impl/shapes/Circle.h"
#include "inh_impl/ShapeVisitor.h"

namespace inh_impl
{
void Circle::accept(inh_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace inh_impl
