#pragma once

#include "Menu.h"
#include "MenuItem.h"
#include "PancakeHouseMenuIterator.h"
#include <vector>

namespace iter
{
class PancakeHouseMenu : public Menu
{
public:
	PancakeHouseMenu();

	std::unique_ptr<Iterator> createIterator() const override
	{
		return std::make_unique<PancakeHouseMenuIterator>(menu_item_group_);
	}

private:
	std::vector<MenuItem> menu_item_group_{};
};

} // namespace iter