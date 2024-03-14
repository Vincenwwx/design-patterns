#include "oo_impl/shapes/Square.h"
#include "oo_impl/ShapeVisitor.h"

namespace oo_impl
{
void Square::accept(oo_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace oo_impl
