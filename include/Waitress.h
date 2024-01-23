#pragma once

#include "Menu.h"
#include "Iterator.h"
#include <vector>

namespace iter
{
class Waitress final
{
public:
    Waitress(std::vector<std::unique_ptr<Menu>> &&menu_list) :
        menu_list_(std::move(menu_list))
    {
    }

    void printMenu() const;

private:
    static void printMenuItem(std::unique_ptr<Iterator> iterator);

    std::vector<std::unique_ptr<Menu>> menu_list_;
};

} // namespace iter