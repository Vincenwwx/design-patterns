#pragma once

#include <string>

namespace fact {
class Pizza
{
public:
    virtual ~Pizza() {};
    virtual std::string type() const = 0;
};

class CheesePizza : public Pizza
{
public:
    std::string type() const override { return "cheese"; };
};

class PepperoniPizza : public Pizza
{
public:
    std::string type() const override { return "pepperoni"; }
};

class HawaiiPizza : public Pizza
{
public:
    std::string type() const override { return "hawaii"; }
};

class VeggiePizza : public Pizza
{
public:
    std::string type() const override { return "veggie"; }
};

} // namespace fact