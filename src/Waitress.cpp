#include "Waitress.h"

#include <iostream>

namespace iter
{
void Waitress::printMenu() const
{
    for(auto const & menu: menu_list_)
    {
        std::cout << "===== " << menu->getName() << " =====\n";
        printMenuItem(menu->createIterator());
        std::cout << '\n';
    }
}

void Waitress::printMenuItem(std::unique_ptr<Iterator> iterator)
{
    while(iterator->hasNext())
    {
        auto const &cur = iterator->next();
        std::cout << "* " << cur.getName()
            << "\n - Description: " << cur.getDescription() 
            << "\n - Veg: " << std::boolalpha << cur.isVegetarian()
            << "\n - Price: " << cur.getPrice() << '\n';
    }
}

} // namespace iter