#pragma once

#include "DenseVector.h"

namespace crtp
{
template <typename T>
class DynamicVector : public DenseVector<DynamicVector<T>>
{
public:
    size_t size() const;
};

}  // namespace crtp
