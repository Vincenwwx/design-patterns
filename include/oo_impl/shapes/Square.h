#pragma once

#include "Shape.h"

namespace oo_impl
{
class Square : public Shape
{
public:
    Square(float bottom_left_x, float bottom_left_y, float width, float height) :
        bottom_left_x_(bottom_left_x), bottom_left_y_(bottom_left_y), width_(width), height_(height)
    {
    }

    float bottomLeftX() const { return bottom_left_x_; }
    float bottomLeftY() const { return bottom_left_y_; }
    float width() const { return width_; }
    float height() const { return height_; }

    std::string_view type() const override { return "Square"; }

    void accept(oo_impl::ShapeVisitor const &v) const override;

private:
    float bottom_left_x_;
    float bottom_left_y_;
    float width_;
    float height_;
};

}  // namespace oo_impl
