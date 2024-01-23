#pragma once

#include "MenuItem.h"

namespace iter
{
class Iterator
{
public:
    Iterator() = default;
    virtual ~Iterator() = default;

    virtual bool hasNext() const = 0;
    virtual const MenuItem &next() const = 0;
};

} // namespace iter