# Factory Pattern
## Overview
Factory pattern can be further categorized as _simple factory_, _factory method pattern_ and _abstract factory pattern_. All showcases are strongly inspired by the book _Head First Design Patterns_.

## Simple Factory Pattern
With simple factory pattern, we simply transform or abstract the object creation code into a separate class or function, such that all clients who want to create objects can use the previously mentioned factory class or function, i.e., have a dependency on it.

## Factory Method Pattern
To use the factory pattern, we create an interface in the base producer or object creator class. All derived producer classes must implement this interface by specfying the concrete products.

## Abstract Factroy Pattern
Compared with the factory method pattern, it is more efficient to create a new serie of pizza with abstract factory. For example, we now want to create a "Berlin-style" pizza store with cheese or pepperoni pizza of corresponding favor, we just need to a new `BerlinPizzaIngredientFactory` along with a `BerlinPizzaStore`, while in terms of factory method, we need to define a new store along with 2 new pizza classes, namely `BerlinStyleCheesePizza`, `BerlinStylePepperoniPizza` and `BerlinStyleVeggiePizza`.