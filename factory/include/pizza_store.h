#pragma once

#include "pizza.h"
#include <string_view>

namespace fact
{
namespace method
{
/**
 * @brief In this file, we demonstrate the factory method pattern, by which a (pure) virtual
 * function (or method) is defined in the base class and decided in the derived class.
 */

class PizzaStore
{
public:
    virtual ~PizzaStore() = default;
    /**
     * Order a pizza.
     * 
     * @note This function defines a standard odering process, i.e., create (by calling the 
     * `createPizza` pure virtual function), prepare, bake, cut and pack. However, what a pizza will
     * be created in the first step is decided during runtime (through polymorphism).
     */
    std::unique_ptr<Pizza> orderPizza(std::string_view type) const;

protected:
    /**
     * Create a Pizza object.
     * 
     * @note The is the factory method of our interest.
     */
    virtual std::unique_ptr<Pizza> createPizza(std::string_view type, bool verbose) const = 0;
};

/**
 * @brief New York style pizza store.
 */
class NewYorkStylePizzaStore : public PizzaStore
{
protected:
    std::unique_ptr<Pizza> createPizza(std::string_view type, bool verbose=false) const override;
};

/**
 * @brief Chicago style pizza store.
 */
class ChicagoStylePizzaStore : public PizzaStore
{
protected:
    std::unique_ptr<Pizza> createPizza(std::string_view type, bool verbose=false) const override;
};

} // namespace fact::method

namespace abs
{

class PizzaStore
{
public:
    PizzaStore() = default;
    virtual ~PizzaStore() = default;

    std::unique_ptr<Pizza> orderPizza(std::string_view type) const;

private:
    // All pizza stores share the same pizza categories (i.e. cheese and pepperoni), while
    // differentiate in the regional favors by using differnt ingredient factories.
    std::unique_ptr<Pizza> createPizza(std::string_view type, bool verbose) const;

    virtual std::unique_ptr<PizzaIngredientFactory> getFactory() const = 0;
};

class NewYorkStylePizzaStore : public PizzaStore
{
private:
    std::unique_ptr<PizzaIngredientFactory> getFactory() const override
    {
        return std::make_unique<NewYorkStylePizzaIngredientFactory>();
    }
};

class ChicagoStylePizzaStore : public PizzaStore
{
private:
    std::unique_ptr<PizzaIngredientFactory> getFactory() const override
    {
        return std::make_unique<ChicagoStylePizzaIngredientFactory>();
    }
};

} // namespace fact::abs

} // namespace fact