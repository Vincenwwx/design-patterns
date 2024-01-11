#include "MenuItem.h"

#include <vector>

namespace iter
{
class PancakeHouseMenu{
public:
    PancakeHouseMenu() {
        menu_item_group_.emplace_back(
            "Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 2.99
        );
        menu_item_group_.emplace_back(
            "Waffles", "Waffles with choice of blueberry or strawberries", true, 3.09
        );
    }

    std::vector<MenuItem> getMenuItems() const { return menu_item_group_; }

    decltype(auto) getIterator() const { return menu_item_group_.begin(); }

private:
    std::vector<MenuItem> menu_item_group_{};
};

} // namespace iter