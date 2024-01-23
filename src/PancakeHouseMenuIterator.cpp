#include "PancakeHouseMenuIterator.h"

namespace iter
{
bool PancakeHouseMenuIterator::hasNext() const
{
    if(menu_items_.empty())
        return false;

    return position_ < menu_items_.size();
}

const MenuItem &PancakeHouseMenuIterator::next() const
{
    return menu_items_[position_++];
}
} // namespace iter
