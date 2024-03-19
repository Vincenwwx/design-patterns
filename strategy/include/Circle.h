#pragma once

#include "Shape.h"
#include "Point.h"
#include "DrawStrategy.h"
#include <iostream>

namespace strategy
{
class Circle : public Shape
{
public:
    explicit Circle(double radius, std::unique_ptr<DrawStrategy<Circle>> &&drawer)
        : radius_(radius), drawer_(std::move(drawer))
    {
    }

    double radius() const { return radius_; }

    void draw() const override { drawer_->draw(*this); }

private:
    double radius_{};
    std::unique_ptr<DrawStrategy<Circle>> drawer_;
};

} // namespace strategy
