# Functions

We can apply template functions to address problems like
- *Count the number of times ‘X’ appears in a `std::deque<char>`*
- *Count the number of times ‘Y’ appears in a `string`*

To be more general, we can use a predicate to judge whether a value satisfies our requirement. 

```cpp
template<typename InputIt, typename DataType, typename Pred>
int count_occurrences(InputIt begin, InputIt end, Pred pred) {
    int count = 0;
    for (auto it = begin; it != end; ++it) {
        if (pred(*it)) {
            count++;
        }
    }
    return count;
}
```

## Lambda Functions

Function pointers could not implement a *less than* function without adding parameters.

Lambda function allows predicate to be more general.
```cpp
// [capture list] (parameter) {implementation}
auto is_less_than = [limit](int val) -> bool {
    return val < limit;
}
```
- The capture list allows the lambda function to know outside variables
- We do not care the type of `is_less_than`

Here are some variances of capture list.
```cpp
[x]()       // capture x by value
[&x]()      // capture x by reference
[x, y]()    // capture x, y by value
[&]()       // capture everything by reference
[&, x]()    // capture everything by reference except x
[=]()       // capture everything by coping
```

## STL Algorithm

- `std::find` 
- `std::search`
- `std::all_of`
- etc