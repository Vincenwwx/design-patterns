#include "Menu.h"
#include "Waitress.h"
#include "DinerMenu.h"
#include "PancakeHouseMenu.h"

#include <iostream>
#include <memory>


int main()
{
    std::vector<std::unique_ptr<iter::Menu>> menu_list{};
    menu_list.push_back(std::make_unique<iter::PancakeHouseMenu>());
    menu_list.push_back(std::make_unique<iter::DinerMenu>());

    auto const waitress = std::make_unique<iter::Waitress>(std::move(menu_list));
    waitress->printMenu();

    return 0;
}