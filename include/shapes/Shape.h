#include <string_view>

namespace object
{
class Shape
{
public:
    virtual std::string_view type() const = 0;
};
 
} // namespace object
