#include <string_view>

#include "simple_pizza_factory.h"

namespace fact {
std::unique_ptr<Pizza> SimplePizzaFactory::createPizza(std::string_view type) {
    std::unique_ptr<Pizza> pizza;
    if(type == "cheese")
        pizza.reset(new CheesePizza{});
    else if(type == "pepperoni")
        pizza.reset(new PepperoniPizza{});
    else if(type == "veggie")
        pizza.reset(new VeggiePizza{});
    else if(type == "hawaii")
        pizza.reset(new HawaiiPizza{});
    return pizza;    
}

} // namespace fact