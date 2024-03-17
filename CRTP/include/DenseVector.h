#pragma once

#include <stddef.h>

namespace crtp
{
template <typename Derived>
class DenseVector
{
public:
    Derived &derived() { return static_cast<Derived &>(*this); }
    Derived const &derived() const { return static_cast<Derived const &>(*this); }

    decltype(auto) size() const { return derived().size(); }

    decltype(auto) operator[](size_t index) { return derived()[index]; }
    decltype(auto) operator[](size_t index) const { return derived()[index]; }

    decltype(auto) begin() { return derived().begin(); }
    decltype(auto) begin() const { return derived().begin(); }
    decltype(auto) end() { return derived().end(); }
    decltype(auto) end() const { return derived().end(); }

protected:
    ~DenseVector() = default;
};

}  // namespace crtp
