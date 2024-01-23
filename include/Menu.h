#pragma once

#include "Iterator.h"
#include <string_view>

namespace iter
{
class Menu
{
public:
    virtual ~Menu() = default;

    virtual std::string_view getName() const = 0;
    virtual std::unique_ptr<Iterator> createIterator() const = 0;
};

} // namespace iter