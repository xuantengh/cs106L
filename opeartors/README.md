# Operators

TL;DR

**Operator overloading tells C++ what it means to use an operator on a class.**

```cpp
Time a, b;
// ...
if (before(a, b)) {
    // ...
}
// use overloaded `<` to represent the meaning of before
if (a < b) {
    // ...
}
```

Two ways to overload operators:
1. member functions

```cpp
    class Time {
        bool operator<(const Time&) const;
        Time operator+(const Time&) const;
        bool operator!() const; // unary
    };
```

When calling, `a < b` becomes `a.operator<(b)`.

2. non-member functions
    
```cpp
    bool operator<(const Time&, const Time&);
```

In STL, **non-member functions** are preferred since:
- allows the LHS to be a non-class type (*e.g.*, `double * Fraction`)
- allows to overload operators with a class we don't control

Allow non-member function to access private members by declaring as a friend function:

```cpp
class Fraction {
    friend ostream& operator<<(ostream& out, const Fraction&);  
};
```

## Rules of Operator Overloading

1. clear meaning
2. reasonably similar to corresponding arithmetic operator

