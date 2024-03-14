#pragma once

#include "var_impl/shapes/Circle.h"
#include "var_impl/shapes/Square.h"

#include <string_view>
#include <vector>

namespace var_impl
{
// Use std::variant to replace the polymorphism through pointer, i.e., std::unique_ptr to object.
using Shape = std::variant<Circle, Square>;
// This has the advantage of reducing memory segmentation as with pointer the managed objects
// can stay anywhere while the vector of objects always occupies a continuous memory space.
using Shapes = std::vector<Shape>;

}  // namespace var_impl
