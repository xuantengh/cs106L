# Template Functions

TL;DR

Template functions are not real function technically, they are a recipe for generating functions via initialization.

A generic function suitable for all data types:
```cpp
template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}
```
Scope of `T` is limited to this one function.

Ways to call template functions:
```cpp
min<std::string>("Trump", "Biden"); // explicitly
min("Trump", "Biden"); //implicitly
```

To avoid confusion, additional template specifications need to be set:
```cpp
min(4, 3.2); // may return 3 since compiler infer T as int

// re-declaration min function
template<typename T, typename U>
auto min(const T& a, const U& b) {
    return a < b ? a : b;
} // this will return 3.2
```

## Application

Count how many times a specific value appears in a `std::vector`.
```cpp
int count_occurrences(const vector<int>& vec, int val) { 
    int count = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == val) count++; 
    }
    return count; 
}
```

Extend to general data type:
```cpp
template<typename DataType>
int count_occurrences(const vector<Datatype>& vec, DataType val) { 
    int count = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == val) count++; 
    }
    return count; 
}
```

Extend `std::vector` to general collections (sequential or associate):
```cpp
template<typename Collection, typename DataType>
count_occurrences(const Collection& arr, DataType val) {
    int count = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == val) count++;
    }
    return count;
}
```

Extend the collection from indexable to general form:
```cpp
template <typename InputIt, typename DataType>
int count_occurrences(InputIt begin, InputIt end, DataType val) {
    int count = 0;
    for (auto it = begin; it != end; ++it) {
        if (*it == val) count++; 
    }
    return count; 
}
```

As this application demonstrates, we build a more generic function step by step.