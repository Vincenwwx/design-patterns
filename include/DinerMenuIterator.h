#pragma once

#include "Iterator.h"
#include "MenuItem.h"

namespace iter
{
const size_t MAX_NUM_DINER_MENU_ITEMS = 2;

class DinerMenuIterator : public Iterator
{
public:
    DinerMenuIterator(const std::array<MenuItem, MAX_NUM_DINER_MENU_ITEMS> &menu_items) :
        menu_items_(menu_items)
    {
    }

    bool hasNext() const override
    {
        return position_ < MAX_NUM_DINER_MENU_ITEMS;
    }

    const MenuItem &next() const override
    {
        return menu_items_.at(position_++);
    }

private:
    mutable size_t position_{0};
    const std::array<MenuItem, MAX_NUM_DINER_MENU_ITEMS> &menu_items_;
};

} // namespace iter