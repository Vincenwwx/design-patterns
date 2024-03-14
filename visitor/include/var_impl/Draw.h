#include "var_impl/shapes/Shape.h"

#include <iostream>

namespace var_impl
{
struct Draw
{
    void operator()(Circle const &c) const
    {
        std::cout << "Draw circle (with variant)." << std::endl;
    }

    void operator()(Square const &c) const
    {
        std::cout << "Draw square (with variant)." << std::endl;
    }
};

}  // namespace var_impl