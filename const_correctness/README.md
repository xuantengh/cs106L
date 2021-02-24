# Const Correctness

TL;DR

Const Correctness is something makes your code to be correct.


Suppose we have code:
```cpp
// vector.cpp
template<typename T>
size_t vector<T>::size() {
    // some code
}

void foo(const vector<int>& vec) {
    std::cout << vec.size() << endl;
}
```

However, it leads to compile error since `size()` function is not marked as const.

A const member function is a function that can **NOT** modify any private member variables. And const functions could only call other const member functions.

An object declared as const that can only call its const member functions.

## How to Fix?

Declare function as const.
```cpp
template<typename T>
size_t vector<T>::size() const {
    // some code
}
```

Now let's consider function `at()`, when we refer to a const `vector` object, we want it to be const, but when it comes to a non-const `vector`, we also want a non-const `at()`.

Solution: include both const and non-const:
```cpp
template<typename T>
class vector {
    // invoked in const vector
    const T& at(size_t index) const;
    // invoked in non-const vector
    T& at(size_t index);
};
```
But code duplication occurs...

## Iterators

```cpp
std::vector<int> non_const_vec{1, 2, 3};
const std::vector<int> const_vec{1, 2, 3};
auto iter = non_const_vec.begin(); // iterator
const auto iter2 = non_const_vec.begin(); // const iterator
auto iter3 = const_vec.begin(); // const_iterator
```

- A `const iterator` is a const object that can't be changed (no incrementing or re-assignment is allowed).
- While const_iterator is provided by const containers (since the internal elements are const).