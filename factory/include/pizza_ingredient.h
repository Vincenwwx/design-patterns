#pragma once

namespace fact::ingredient
{
//----------------
// Dough
//----------------
class Dough
{
public:
    virtual ~Dough() = default;
};

class ThinCrustDough : public Dough
{};

class ThickCrustDough : public Dough
{};

//----------------
// Sauce
//----------------
class Sauce
{
public:
    virtual ~Sauce() = default;
};

class MarinaraSauce : public Sauce
{};

class PlumTomatoSauce : public Sauce
{};

//----------------
// Cheese
//----------------
class Cheese
{
public:
    virtual ~Cheese() = default;
};

class ReggianoCheese : public Cheese
{};

class MozarellaCheese : public Cheese
{};

}  // namespace fact::ingredient