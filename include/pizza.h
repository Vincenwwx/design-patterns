#pragma once

#include <string>
#include <iostream>

namespace fact {
class Pizza
{
public:
    Pizza(bool verbose = false) : verbose_(verbose)
    {
    }
    virtual ~Pizza() {};

    virtual std::string type() const = 0;
    void prepare() const { if(verbose_) std::cout << "Prepare " << type() << std::endl; }
    void bake() const { if(verbose_) std::cout << "Bake " << type() << std::endl; }
    void cut() const { if(verbose_) std::cout << "Cut " << type() << std::endl; }
    void pack() const { if(verbose_) std::cout << "Pack " << type() << std::endl; }

private:
    bool verbose_;
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
    NewYorkStyleCheesePizza(bool verbose = false) : Pizza(verbose)
    {
    }

    std::string type() const override { return "New York style cheese pizza"; };
};

class NewYorkStylePepperoniPizza : public Pizza
{
public:
    NewYorkStylePepperoniPizza(bool verbose = false) : Pizza(verbose)
    {
    }

    std::string type() const override { return "New York style pepperoni pizza"; }
};

class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza(bool verbose = false) : Pizza(verbose)
    {
    }

    std::string type() const override { return "Chicago stype cheese pizza"; };
};

class ChicagoStylePepperoniPizza : public Pizza
{
public:
    ChicagoStylePepperoniPizza(bool verbose = false) : Pizza(verbose)
    {
    }

    std::string type() const override { return "Chicago stype pepperoni pizza"; }
};
} // namespace fact::method

} // namespace fact