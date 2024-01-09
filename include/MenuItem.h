#pragma once

#include <string>

namespace iter
{
class MenuItem
{
public:
    MenuItem(
        const std::string &name, const std::string &description, bool is_vegetarian, double price
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