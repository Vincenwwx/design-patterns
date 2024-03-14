#pragma once

#include "pizza_ingredient.h"
#include <string>

#include <memory>

namespace fact
{
class PizzaIngredientFactory
{
public:
    PizzaIngredientFactory() = default;
    virtual ~PizzaIngredientFactory() = default;

    virtual std::string style() const = 0;
    virtual std::unique_ptr<ingredient::Dough> createDough() const = 0;
    virtual std::unique_ptr<ingredient::Sauce> createSauce() const = 0;
    virtual std::unique_ptr<ingredient::Cheese> createCheese() const = 0;
};

class NewYorkStylePizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    std::string style() const override { return std::string{"NewYork"}; }

    std::unique_ptr<ingredient::Dough> createDough() const override
    {
        return std::make_unique<ingredient::ThinCrustDough>();
    }

    std::unique_ptr<ingredient::Sauce> createSauce() const override
    {
        return std::make_unique<ingredient::MarinaraSauce>();
    }

    std::unique_ptr<ingredient::Cheese> createCheese() const override
    {
        return std::make_unique<ingredient::ReggianoCheese>();
    }
};

class ChicagoStylePizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    std::string style() const override { return std::string{"Chicago"}; }

    std::unique_ptr<ingredient::Dough> createDough() const override
    {
        return std::make_unique<ingredient::ThickCrustDough>();
    }

    std::unique_ptr<ingredient::Sauce> createSauce() const override
    {
        return std::make_unique<ingredient::PlumTomatoSauce>();
    }

    std::unique_ptr<ingredient::Cheese> createCheese() const override
    {
        return std::make_unique<ingredient::MozarellaCheese>();
    }
};

}  // namespace fact