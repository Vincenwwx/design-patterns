#include "pizza.h"
#include "pizza_store.h"
#include "simple_pizza_factory.h"

#include <iostream>
#include <string>
#include <vector>

void showSimpleFactoryPattern(std::vector<std::string> const &types)
{
    std::unique_ptr<fact::Pizza> pizza;
    bool pass{true};
    for (auto const &pizza_type : types)
    {
        pizza = fact::simple::SimplePizzaFactory::createPizza(pizza_type);
        if (pizza == nullptr)
        {
            if (pizza_type != "")
            {
                std::cerr << "Failed create NULL pizza" << '\n';
                pass = false;
            }
        } else if (pizza->type() != pizza_type)
        {
            pass = false;
            std::cerr << "Wrong pizza created: " << pizza->type() << "(want: " << pizza_type
                      << ")\n";
        }
    }

    if (pass)
        std::cout << "[PASS] simple factory pattern\n" << std::endl;
}

void showFactoryMethodPattern(std::vector<std::string> const &types)
{
    auto const new_york_style_pizza_store =
        std::make_unique<fact::method::NewYorkStylePizzaStore>();
    auto const chicago_style_pizza_store = std::make_unique<fact::method::ChicagoStylePizzaStore>();

    bool pass{true};
    for (auto const &type : types)
    {
        auto const new_york_style_pizza = new_york_style_pizza_store->orderPizza(type);
        auto const chicago_style_pizza = chicago_style_pizza_store->orderPizza(type);
        if (new_york_style_pizza == nullptr || chicago_style_pizza == nullptr)
            pass = false;
    }

    if (pass)
        std::cout << "[PASS] factory method pattern\n" << std::endl;
}

void showAbstractFactoryPattern()
{
    auto new_york_pizza_store = std::make_unique<fact::abs::NewYorkStylePizzaStore>();
    auto new_york_cheese_pizza = new_york_pizza_store->orderPizza("cheese");
    auto new_york_pepperoni_pizza = new_york_pizza_store->orderPizza("pepperoni");

    auto chicago_pizza_store = std::make_unique<fact::abs::ChicagoStylePizzaStore>();
    auto chicago_cheese_pizza = chicago_pizza_store->orderPizza("cheese");
    auto chicago_pepperoni_pizza = chicago_pizza_store->orderPizza("pepperoni");
}

int main()
{
    std::vector<std::string> PIZZA_TYPES{"cheese", "pepperoni", "veggie", "hawaii", ""};
    showSimpleFactoryPattern(PIZZA_TYPES);

    PIZZA_TYPES = std::vector<std::string>{"cheese", "pepperoni"};
    showFactoryMethodPattern(PIZZA_TYPES);

    showAbstractFactoryPattern();

    return 0;
}