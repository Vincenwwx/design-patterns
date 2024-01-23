#pragma once

#include "Iterator.h"
#include <string_view>

namespace iter
{
class Menu
{
public:
    Menu(std::string_view name) : name_(name)
    {
    }
    virtual ~Menu() = default;

    std::string_view getName() const
    {
        return name_;
    }

    virtual std::unique_ptr<Iterator> createIterator() const = 0;

private:
    std::string_view name_;
};

} // namespace iter