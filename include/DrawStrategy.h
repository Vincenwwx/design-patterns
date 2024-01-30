#pragma once

namespace strategy
{
template <typename T>
class DrawStrategy
{
public:
    virtual ~DrawStrategy() = default;

    virtual void draw(const T &) const = 0;
};

} // namespace strategy
