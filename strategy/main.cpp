#include "Circle.h"
#include "MetaCircleStrategy.h"
#include "OpenGlCircleStrategy.h"
#include "Shape.h"
#include <vector>

using namespace strategy;

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes{};

    shapes.emplace_back(std::make_unique<Circle>(2.2, std::make_unique<OpenGlCircleStrategy>()));
    shapes.emplace_back(std::make_unique<Circle>(3.2, std::make_unique<MetaCircleStrategy>()));

    for (auto const &shape : shapes)
    {
        shape->draw();
    }

    return 0;
}