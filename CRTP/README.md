# Curiously Recurring Template Pattern (CRTP)

---
<h2>Introduction</h2>

CRTP is a pattern where a class uses itself as a template parameter.

```cpp
template<class Derived>
class Base
{
};
 
class Derived1 : public Base<Derived1> {};
class Derived2 : public Base<Derived2> {};
...
```
---
<h2>Analysis</h2>

This approach is beneficial for establishing static polymorphic behaviors without relying on virtual functions.

<h3>Pros</h3>

- __Lower memory overhead__: There's no need for additional space for a virtual pointer and table. This is particularly crucial in some use cases like embedded systems;

- __Faster function calls__: Functions are dispatched directly, bypassing the virtual table, allowing the compiler greater opportunities for optimizations like inlining.

<h3>Cons</h3>

- Less straightforward to understand;

- __Limited flexibility__: Derived classes cannot be addressed through a pointer or reference to base classes.

```cpp
// Operations like this are no more allowed.
std::vector<std::unique_ptr<Base>> objects;
for(auto const &obj : objects) { ... }
```

---

<h2>Q&A</h2>

<h3>Q1: Why the "derived" class need to inherit from the base class?</h3>

To maintain some low level of the polymorhism. (See implementation of the function `printSize()` in _main.cpp_)

<h3>Q2: Why use a protected destructor for the base class?</h3>

To begin with, we need to avoid using virtual functions, such as the virtual destructor, in CRTP. Also, the base class should mainly serve as a __template__, and resource management should be handled in the derived classes. We should prevent situations where the object is destroyed through the destructor of the base class by the caller.

```cpp
std::unque_ptr<Base> p = std::make_unique<Derive>();
// Now the p will be destroyed using the destructor 
// of the base class, which is unexpected.
```
---