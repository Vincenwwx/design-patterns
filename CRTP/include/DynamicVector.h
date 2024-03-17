#pragma once

#include "DenseVector.h"

#include <vector>

namespace crtp
{
template <typename T>
class DynamicVector : public DenseVector<DynamicVector<T>>
{
public:
    DynamicVector(std::initializer_list<T> args) : elements_{args} {}

    size_t size() const { return elements_.size(); };

    T &operator[](size_t index) { return elements_[index]; }
    T const &operator[](size_t index) const { return elements_[index]; }

    std::vector<T>::iterator begin() { return elements_.begin(); }
    std::vector<T>::const_iterator begin() const { return elements_.cbegin(); }
    std::vector<T>::iterator end() { return elements_.end(); }
    std::vector<T>::const_iterator end() const { return elements_.cend(); }

private:
    std::vector<T> elements_{};
};

}  // namespace crtp
