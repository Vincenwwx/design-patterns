#include "pizza_store.h"

namespace fact::method
{
std::unique_ptr<Pizza> PizzaStore::orderPizza(std::string_view type) const {
    std::cout << "------ Order starts -------" << '\n';
    auto pizza = createPizza(type);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->pack();
    std::cout << "------ Order ends -------\n" << std::endl;

    return pizza;
}

std::unique_ptr<Pizza> NewYorkStylePizzaStore::createPizza(std::string_view type) const
{
    std::unique_ptr<Pizza> pizza;
    if(type == "cheese")
        pizza.reset(new NewYorkStyleCheesePizza{});
    else if(type == "pepperoni")
        pizza.reset(new NewYorkStylePepperoniPizza{});
    return pizza;
}

std::unique_ptr<Pizza> ChicagoStylePizzaStore::createPizza(std::string_view type) const
{
    std::unique_ptr<Pizza> pizza;
    if(type == "cheese")
        pizza.reset(new ChicagoStyleCheesePizza{});
    else if(type == "pepperoni")
        pizza.reset(new ChicagoStylePepperoniPizza{});
    return pizza;
}

} // namespace fact::method