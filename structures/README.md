# Structure in C++

There are nothing new in this lecture but still some valuable points that I don't know before.

## Initialization
Here we assume that there is a structure defined in this way:
```cpp
struct Student {
    string name;
    string state;
    int age;
};
```

Suppose we want to create a instance of `Student`, instead of initialize it like:
```cpp
Student s;
s.name = "Trump";
s.state = "CA";
s.age = 20;
```
We can achieve this in an elegant way:
```cpp
Student s = {"Trump", "CA", 20};
```

## Built-in Structures in `std`

Here are some built-in types defined in `std`.
```cpp
::std::pair<int, int> point;
::std::tuple<string, int, int> query_result;
```
To access members in in `::std::pair`, we can use `first` and `second`. And for members in `::std::tuple`, we can get them like:
```cpp
string name = std::get<0>(query_result);
int num = std::get<1>(query_result);
```

## Structured Binding

```cpp
auto p = ::std::make_pair(“s”, 5); 
auto [a, b] = p;
```
We can use code shown above to access members in a struct without listing fields explicitly.

**❗️Note: Use C++17 standard to compile above example.**
