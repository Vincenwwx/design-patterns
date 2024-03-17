#pragma once

#include "DenseVector.h"

#include <array>

namespace crtp
{
template <typename T, size_t Size>
class StaticVector : public DenseVector<StaticVector<T, Size>>
{
public:
    StaticVector(std::initializer_list<T> args) { std::ranges::copy(args, elements_.begin()); }
    constexpr size_t size() const { return Size; };

    T &operator[](size_t index) { return elements_[index]; }
    T const &operator[](size_t index) const { return elements_[index]; }

    std::array<T, Size>::iterator begin() { return elements_.begin(); }
    std::array<T, Size>::const_iterator begin() const { return elements_.cbegin(); }
    std::array<T, Size>::iterator end() { return elements_.end(); }
    std::array<T, Size>::const_iterator end() const { return elements_.cend(); }

private:
    std::array<T, Size> elements_{};
};

}  // namespace crtp
