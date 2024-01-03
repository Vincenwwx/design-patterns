#pragma once

#include <string>
#include <iostream>

namespace fact {
class Pizza
{
public:
    virtual ~Pizza() {};

    virtual std::string type() const = 0;
    void prepare() const { std::cout << "Prepare " << type() << " pizza" << std::endl; }
    void bake() const { std::cout << "Bake " << type() << " pizza" << std::endl; }
    void cut() const { std::cout << "Cut " << type() << " pizza" << std::endl; }
    void pack() const { std::cout << "Pack " << type() << " pizza" << std::endl; }
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