# Containers

TL;DR

STL (Standard Template Library) consists of four aspects:
- Container (Adaptors)
- Iterators
- Functions
- Algorithms

Container adaptors are wrappers for sequence containers.

## Sequence Containers

Such as `::std::vector` and `::std::deque`.

`::std::deque` has the exact same functions as `::std::vector` but also has `push_front` and `pop_front`.

Comparison between sequence containers:

  | | `std::vector` | `std::deque` | `std::list` |  
  |-|-|-|-|  
  | Indexed Access | Super Fast | Fast | Impossible |  
  | Insert/remove front | Slow | Fast | Fast |  
  | Insert/remove back | Super Fast | Very Fast | Fast |  
  | Ins/rem elsewhere | Slow | Fast | Very Fast |  
  | Memory | Low | High | High |  

The best way to create a `std::vector` containing 1,000,000 integers:
```cpp
std::vector v;
v.reserve(1000000); // reserve memory space for data
for (size_t i = 0; i < 1000000; i++) {
    v.push_back(i);
}
```
And some other tips:
- Consider use `shrink_to_fit` to squeeze the memory space
- Use `empty` instead of checking `size() == 0`
- Do not use `vector<bool>` (it is not a STL container, and does not contain `bool`)
  
## Container Adaptors

How `std::stack` defined?
```cpp
// in header <stack>
template<class T, class Container = std::deque<T>>
class stack;
```
Container is a class template parameter.

```cpp
std::stack<int> stack_d; // Container = std::deque
std::stack<int, std::vector<int>> stack_v; // Container = std::vector
std::stack<int, std::list<int>> stack_l; // Container = std::list
```
To check the interfaces, go to [here](https://en.cppreference.com/w/cpp/container/stack).

STL adaptors: `std::stack`, `std::queue`, `std::priority_queue`.

## Associative Containers

`std::map` provides 1-to-1 mappings from K to V.

`std::set` stores a set of items which must have keys.

`std::multimap` & `std::multiset` duplicate keys are permitted. (less used)

Code for iterate `set` and `map`, as mentioned in previous lectures.
```cpp
 for (const auto& element : s) {
    // do stuff with key
}
for (const auto& [key, value] : m) {
    // do stuff with key, value
}
```

`unordered_set` and `unordered_map` act almost same as `set` and `map`, with two main difference:

- They use hash functions instead of comparison operator
- They are faster than ordered associate containers
