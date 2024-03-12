#include "Square.h"
#include "ShapeVisitor.h"

namespace object
{
void Square::accept(oo_impl::ShapeVisitor const &v) const
{
    v.visit(*this);
}
}  // namespace object
