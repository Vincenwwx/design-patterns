#include "Square.h"
#include "ShapeVisitor.h"

namespace oo_impl
{
void Square::accept(oo_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace oo_impl
