#include "pizza.h"
#include "simple_pizza_factory.h"

#include <iostream>

int main() {
    std::array<std::string, 5> PIZZA_TYPES{"cheese", "pepperoni", "veggie", "hawaii", ""};
    std::unique_ptr<fact::Pizza> pizza;
    bool pass{true};
    for(const auto &pizza_type : PIZZA_TYPES) {
        pizza = fact::SimplePizzaFactory::createPizza(pizza_type);
        if(pizza == nullptr) {
            if(pizza_type != "") {
                std::cerr << "Failed create NULL pizza" << '\n';
                pass = false;
            }
        }
        else if(pizza->type() != pizza_type) {
            pass = false;
            std::cerr << "Wrong pizza created: " << pizza->type()
                      << "(want: " << pizza_type << ")\n";
        }
    }

    if(pass)
        std::cout << "All tests passed." << std::endl;
    return 0;
}