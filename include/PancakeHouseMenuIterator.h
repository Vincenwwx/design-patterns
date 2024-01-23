#pragma once

#include "Iterator.h"
#include "MenuItem.h"

namespace iter
{
class PancakeHouseMenuIterator : public Iterator
{
public:
    PancakeHouseMenuIterator(const std::vector<MenuItem> &menu_items) : menu_items_(menu_items)
    {
    }

    bool hasNext() const override;
    
    const MenuItem &next() const override;

private:
    mutable size_t position_{0};
    const std::vector<MenuItem> &menu_items_;
};

} // namespace iter