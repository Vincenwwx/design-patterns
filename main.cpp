#include "Circle.h"
#include "Draw.h"
#include "Square.h"

#include <vector>

void showImplementationWithInheritance()
{
    std::vector<std::unique_ptr<object::Shape>> shapes;
    shapes.emplace_back(new object::Circle{1, 1, 2});
    shapes.emplace_back(new object::Circle{1, 2, 2});
    shapes.emplace_back(new object::Circle{2, 1, 2});
    shapes.emplace_back(new object::Square{1.1, 2.2, 2.0, 3.0});
    shapes.emplace_back(new object::Square{1.1, 2.4, 1.0, 3.0});

    oo_impl::Draw draw{};
    for (auto const &shape : shapes)
    {
        shape->accept(draw);
    }
}

int main()
{
    showImplementationWithInheritance();

    return 0;
}