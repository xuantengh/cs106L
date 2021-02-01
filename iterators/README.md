# Iterators

TL;DR

Iterators allow iteration over any container whether ordered or unordered.

## Operations

STL iterator supports following operations:
```cpp
std::set<T> s;
std::set<T>::iterator it = s.begin(); // use auto to be gentle
it++; // point to next element
T elem = *it; // dereference
(it == s.end());
it = another_it; // copy construction
```

Use iterator to loop over ordered containers:
```cpp
::std::set<int> set = {1, 2, 3, 4, 5};
for (auto it = set.begin(); it != set.end(); ++it) {
    const auto& elem = *it;
    // ...
}
```
Remember there is another way:
```cpp
for (const auto& elem: set) {
    // ...
}

// for map
for (const auto& [k, v]: map) {
    // ...
}
```

These are equivalent:
```cpp
auto key = (*it).first;
auto key = it->first;
```

## Types of Iterators
All iterators are incrementable (`++`).

- Output iterators can be on the left side of `=`:
    ```cpp
    *it = value;
    ```

- Backward iterators
    ```cpp
    for (std::vector<T>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        // ...
    }
    ``` 

- Random access iterators support indexing by integers
    ```cpp
    it += 3;
    auto elem = it[5]; // *(it + 5)
    ```