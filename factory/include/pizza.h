#pragma once

#include "pizza_ingredient_factory.h"
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

namespace abs
{
/**
 * @brief Base class defined for present the abstract factory method. Unlike the factory method
 * pattern, the `(NewYork|Chicago|..)Style(Cheese|Pepperoni|...)Pizza` classes are abstracted into
 * `(Cheese|Pepperoni)Pizza` classes, combining with a input factory to control the region.
 */
class Pizza
{
public:
    Pizza(std::unique_ptr<PizzaIngredientFactory> &&factory, bool verbose=false) : 
        style_(factory->style()),
        dough_(factory->createDough()),
        sauce_(factory->createSauce()),
        cheese_(factory->createCheese()),
        verbose_(verbose)
    {
    }
    virtual ~Pizza() = default;

    virtual std::string type() const = 0;
    void prepare() const {
        if(verbose_)
            std::cout << "Prepare " << style_ << "-style " << type() << " pizza" << std::endl;
    }
    void bake() const { if(verbose_) std::cout << "Bake " << style_ << "-style " << type() << std::endl; }
    void cut() const { if(verbose_) std::cout << "Cut " << style_ << "-style " << type() << std::endl; }
    void pack() const { if(verbose_) std::cout << "Pack " << style_ << "-style " << type() << std::endl; }

private:
    std::string style_;
    std::unique_ptr<ingredient::Dough> dough_;
    std::unique_ptr<ingredient::Sauce> sauce_;
    std::unique_ptr<ingredient::Cheese> cheese_;

    bool verbose_;
};

class CheesePizza : public Pizza
{
public:
    CheesePizza(std::unique_ptr<PizzaIngredientFactory> &&factory, bool verbose=false)
        : Pizza(std::move(factory), verbose)
    {
    }

    std::string type() const override { return "cheese pizza"; }
};

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> &&factory, bool verbose=false)
        : Pizza(std::move(factory), verbose)
    {
    }

    std::string type() const override { return "pepperoni pizza"; }
};

} // namespace fact::abs

} // namespace fact