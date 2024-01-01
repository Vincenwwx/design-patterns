#include <string>

class Pizza
{
public:
    virtual std::string type() const = 0;
};

class CheesePizza : public Pizza
{
public:
    std::string type() const override { return "Cheese pizza"; };
};

class PepperoniPizza : public Pizza
{
public:
    std::string type() const override { return "Pepperoni pizza"; }
};

class HawaiiPizza : public Pizza
{
public:
    std::string type() const override { return "Hawaii pizza"; }
};

class VeggiePizza : public Pizza
{
public:
    std::string type() const override { return "Veggie pizza"; }
};