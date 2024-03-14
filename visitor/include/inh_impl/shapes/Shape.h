#pragma once

#include <string_view>

namespace inh_impl
{
class ShapeVisitor;

class Shape
{
public:
    virtual ~Shape() = default;

    virtual std::string_view type() const = 0;

    virtual void accept(inh_impl::ShapeVisitor const &v) const = 0;
};

}  // namespace inh_impl