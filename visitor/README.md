# Visitor Pattern

## Introduction
> Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.  
>
> -- Erich Gamma et al., _Design Patterns: Elements of Reusable Object-Oriented Software_.

Visitor pattern is suitable for those scenarios where the types of classes are relatively fixed, new operations (on those types) are required to be created.

## Implementation
The visitor pattern can be implemented with either the helf of inheritance, or `std::variant` (since C++17).