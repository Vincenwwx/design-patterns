#include "Shape.h"
#include "Circle.h"
#include "OpenGlCircleStrategy.h"
#include "MetaCircleStrategy.h"
#include <vector>

using namespace strategy;

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes{};

    shapes.emplace_back(
        std::make_unique<Circle>(2.2, std::make_unique<OpenGlCircleStrategy>())
    );
    shapes.emplace_back(
        std::make_unique<Circle>(3.2, std::make_unique<MetaCircleStrategy>())
    );

    for(const auto &shape : shapes)
    {
        shape->draw();
    }

    return 0;
}