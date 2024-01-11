#include "MenuItem.h"

#include <array>

namespace iter
{
static const size_t MAX_NUM_ITEMS = 2;

class DinerMenu
{
public:
    DinerMenu() :
        menu_item_group_{
            MenuItem { "Vegetarian BLT", "Bacon with lettuce", true, 2.99 },
            MenuItem { "Soup", "Soup with a side of potato", false, 3.29}
        }
    {
    }

    std::array<MenuItem, MAX_NUM_ITEMS> getMenuItems() const { return menu_item_group_; }

    decltype(auto) getIterator() const { return menu_item_group_.begin(); }

private:
    std::array<MenuItem, MAX_NUM_ITEMS> menu_item_group_;
};

} // namespace iter