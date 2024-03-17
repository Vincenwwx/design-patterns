# Curiously Recurring Template Pattern (CRTP)

---
## Introduction
CRTP is a pattern where a class uses itself as a template parameter.
```cpp
template<class Derived>
class Base {};
 
class Derived1 : public Base<Derived1> {};
class Derived2 : public Base<Derived2> {};
...
```
---
## Pros & Cons
This is useful for creating (static) polymorphic behaviors without using virtual functions. Therefore, the advantages of this pattern include:
- Reduced memory cost as no extra space needed for virtual pointer and table, which can be critical for small classes;

- Reduced time cost for function call: function calla are dispatched directly (not via the vtable) and the compiler has more chance for optimization such as inlining.

This pattern has centainly disadvantages:

- Less intuitive;
- Less flexibility: Derived classes are not addressable via pionter or reference to base classes;

```cpp
// Operations similiar like this are no more possible.
std::vector<std::unique_ptr<Base>> objects;
for(auto const &obj : objects) { ... }
```

---

## Q&A

### Q1: Why the "derived" class need to inherit from the base class?

<u>Ans</u>:
To maintain some low level of the polymorhism. (See parameter of the function `printSize` in _main.cpp_)

### Q2: Why use a protected destructor for the base class?

<u>Ans</u>: 
To begin with, we need to avoid using virtual functions, such as the virtual destructor, in CRTP. Also, the base class should mainly serve as a __template__, and resource management should be handled in the derived classes. We should prevent situations where the object is destroyed through the destructor of the base class by the caller.

```cpp
std::unque_ptr<Base> p = std::make_unique<Derive>();
// Now the p will be destroyed using the destructor 
// of the base class, which is unexpected.
```
---