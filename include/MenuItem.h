#pragma once

#include <string>
#include <string_view>

namespace iter
{
class MenuItem
{
public:
    MenuItem(
        std::string_view name, const std::string_view description, bool is_vegetarian, double price
    ) : 
        name_(name), description_(description), is_vegetarian_(is_vegetarian), price_(price)
    {
    }

    std::string getName() const { return name_; }
    std::string getDescription() const { return description_; }
    bool isVegetarian() const { return is_vegetarian_; }
    double getPrice() const { return price_; }

private:
    std::string name_{};
    std::string description_{};
    bool is_vegetarian_{false};
    double price_{.0};
};

} // namespace iter