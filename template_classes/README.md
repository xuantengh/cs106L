# Template Classes

TL;DR

Essential topics in C++ Classes:
- Template Classes
- Const-Correctness
- Operator Overloading
- Special Member Functions
- Move Semantics
- RAII (Resource Acquisition Is Initialization)

The syntax of template classes is similar to template functions (`typename T`).

## Type Aliases

Give a type another name:
```cpp
using char_vec = std::vector<char>;
using value_type = T; // internal declaration of a template class
```
Make sure your clients have a standardized way to access important types.

But before class specifies, key word `typename` should be exploited:
```cpp
// before class being specified
template<typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos, int value);
// another example
typename vector<T>::iterator iter = vec.begin();
```