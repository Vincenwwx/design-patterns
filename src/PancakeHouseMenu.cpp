#include "PancakeHouseMenu.h"

namespace iter
{
PancakeHouseMenu::PancakeHouseMenu() : Menu("Pancake House Menu")
{
	menu_item_group_.emplace_back(
		"Pancake Breakfast", "Pancakes with scrambled eggs and toast", true, 5.99
	);
	menu_item_group_.emplace_back(
		"Waffles", "Waffles with choice of blueberry or strawberries", true, 3.09
	);
}
} // namespace iter
