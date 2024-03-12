#pragma once

#include <string_view>

namespace oo_impl
{
class ShapeVisitor;
}  // namespace oo_impl

namespace object
{
class Shape
{
public:
    virtual ~Shape() = default;

    virtual std::string_view type() const = 0;

    virtual void accept(oo_impl::ShapeVisitor const &v) const = 0;
};

}  // namespace object
