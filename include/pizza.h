#pragma once

#include <string>
#include <iostream>

namespace fact {
class Pizza
{
public:
    virtual ~Pizza() {};

    virtual std::string type() const = 0;
    void prepare() const { std::cout << "Prepare " << type() << std::endl; }
    void bake() const { std::cout << "Bake " << type() << std::endl; }
    void cut() const { std::cout << "Cut " << type() << std::endl; }
    void pack() const { std::cout << "Pack " << type() << std::endl; }
};

namespace simple
{
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

} // namespace fact::simple

namespace method
{
class NewYorkStyleCheesePizza : public Pizza
{
public:
    std::string type() const override { return "New York style cheese pizza"; };
};

class NewYorkStylePepperoniPizza : public Pizza
{
public:
    std::string type() const override { return "New York style pepperoni pizza"; }
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
    std::string type() const override { return "Chicago stype cheese pizza"; };
};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
    std::string type() const override { return "Chicago stype pepperoni pizza"; }
};
} // namespace fact::method

} // namespace fact