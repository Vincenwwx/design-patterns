#pragma once

#include "Menu.h"
#include "MenuItem.h"
#include "DinerMenuIterator.h"
#include <array>

namespace iter
{
class DinerMenu : public Menu
{
public:
    DinerMenu() :
        Menu("Diner Menu"),
        menu_item_group_{
            MenuItem { "Vegetarian BLT", "Bacon with lettuce", true, 2.99 },
            MenuItem { "Soup", "Soup with a side of potato", false, 3.29}
        }
    {
    }

    std::unique_ptr<Iterator> createIterator() const override
    {
        return std::make_unique<DinerMenuIterator>(menu_item_group_);
    }

private:
    std::array<MenuItem, MAX_NUM_DINER_MENU_ITEMS> menu_item_group_;
};

} // namespace iter