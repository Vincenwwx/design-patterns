#pragma once

#include "Shape.h"

namespace inh_impl
{
class Circle : public Shape
{
public:
    Circle(float center_x, float center_y, float radius) :
        center_x_(center_x), center_y_(center_y), radius_(radius)
    {
    }

    float centerX() const { return center_x_; }
    float centerY() const { return center_y_; }
    float radius() const { return radius_; }

    std::string_view type() const override { return "Circle"; }

    void accept(ShapeVisitor const &v) const override;

private:
    float center_x_;
    float center_y_;
    float radius_;
};

}  // namespace inh_impl