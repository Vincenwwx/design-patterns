#pragma once

#include "pizza.h"

#include <memory>
#include <string_view>

namespace fact::simple
{
/**
 * @brief The simple pizza factory factors pizza initialization out and can be referenced by
 * different clients. To add new type of pizza, only the simple pizza factory needs to be updated,
 * while no changes have to be made to the clients.
 */
class SimplePizzaFactory
{
public:
    static std::unique_ptr<Pizza> createPizza(std::string_view type);
};

} // namespace fact::simple