#include "pizza_store.h"

namespace fact
{
static const bool VERBOSE = false;

namespace method
{
std::unique_ptr<Pizza> PizzaStore::orderPizza(std::string_view type) const {
    auto pizza = createPizza(type, VERBOSE);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->pack();

    return pizza;
}

std::unique_ptr<Pizza> NewYorkStylePizzaStore::createPizza(
    std::string_view type, bool verbose
) const {
    std::unique_ptr<Pizza> pizza;
    if(type == "cheese")
        pizza.reset(new NewYorkStyleCheesePizza{verbose});
    else if(type == "pepperoni")
        pizza.reset(new NewYorkStylePepperoniPizza{verbose});
    return pizza;
}

std::unique_ptr<Pizza> ChicagoStylePizzaStore::createPizza(
    std::string_view type, bool verbose
) const {
    std::unique_ptr<Pizza> pizza;
    if(type == "cheese")
        pizza.reset(new ChicagoStyleCheesePizza{verbose});
    else if(type == "pepperoni")
        pizza.reset(new ChicagoStylePepperoniPizza{verbose});
    return pizza;
}

} // namespace fact::method

namespace abs
{
std::unique_ptr<Pizza> PizzaStore::orderPizza(std::string_view type) const {
    auto pizza = createPizza(type, VERBOSE);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->pack();

    return pizza;
}

std::unique_ptr<Pizza> PizzaStore::createPizza(std::string_view type, bool verbose) const {
    std::unique_ptr<Pizza> pizza;
    if(type == "cheese")
        pizza.reset(new CheesePizza{getFactory(), verbose});
    else if(type == "pepperoni")
        pizza.reset(new PepperoniPizza{getFactory(), verbose});
    return pizza;
}

} // namespace fact::abs

} // namespace fact