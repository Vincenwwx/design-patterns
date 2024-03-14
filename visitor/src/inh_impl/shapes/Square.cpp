#include "inh_impl/shapes/Square.h"
#include "inh_impl/ShapeVisitor.h"

namespace inh_impl
{
void Square::accept(inh_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace inh_impl
