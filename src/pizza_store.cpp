#include "pizza_store.h"

namespace fact::method
{
static const bool VERBOSE = false;

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