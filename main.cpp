#include "oo_impl/Draw.h"
#include "oo_impl/shapes/Circle.h"
#include "oo_impl/shapes/Square.h"
#include "var_impl/shapes/Shape.h"
#include "var_impl/util.h"

#include <vector>

void showImplementationWithInheritance()
{
    using namespace oo_impl;
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(new Circle{1, 1, 2});
    shapes.emplace_back(new Circle{1, 2, 2});
    shapes.emplace_back(new Circle{2, 1, 2});
    shapes.emplace_back(new Square{1.1, 2.2, 2.0, 3.0});
    shapes.emplace_back(new Square{1.1, 2.4, 1.0, 3.0});

    Draw draw{};
    for (auto const &shape : shapes)
    {
        shape->accept(draw);
    }
}

void showImplementationWithStdVariant()
{
    using namespace var_impl;
    Shapes shapes;
    shapes.emplace_back(Circle{1, 1, 2});
    shapes.emplace_back(Circle{1, 2, 2});
    shapes.emplace_back(Circle{2, 1, 2});
    shapes.emplace_back(Square{1.1, 2.2, 2.0, 3.0});
    shapes.emplace_back(Square{1.1, 2.4, 1.0, 3.0});

    drawAllShapes(shapes);
}

int main()
{
    showImplementationWithInheritance();
    showImplementationWithStdVariant();

    return 0;
}