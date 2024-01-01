#pragma once

#include "pizza.h"

#include <memory>
#include <string_view>

namespace fact {
class SimplePizzaFactory
{
public:
    std::unique_ptr<Pizza> createPizza(std::string_view type);
};

} // namespace fact