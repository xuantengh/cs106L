# Initialization & Reference

TL;DR

**What is initialization?**

Initialization is how we provide initial values to variables.

**What is reference?**

Reference is an alias to referenced variable. Any change functioned on reference will also take effect on the referenced one.

## Initialization 

```cpp
int x = 5;
int y;
y = 6;

// complex type
::std::pair<bool, int> some_pair = ::std::make_pair(true, 5);
Student s = {"Trump", "CA", 45};
```

Uniform initialization provides a way for us to use *brackets* to initialize anything briefly.

A more concise way for uniform initialization:
```cpp
Student s{"Biden", "CA", 46};
::std::pair some_pair{true, 5};

int x{3}; // built-in types
::std::vector<int> v{3, 5, 7};
```

Faster way to init a vector with a certain number of elements:
```cpp
::std::vector<int> v(5, 3); // equals to {3, 3, 3, 3, 3}
```

## Reference

Settings a new value to a ref is exactly same as setting the value to the origin referenced variable. We can't change what variable a reference refers.

Reference pitfall:
```cpp
int& x = 5;
```

Const reference:
```cpp
::std::vector<int> vec{1, 2, 3};
::std::vector<int>& ref = vec;
const ::std::vector<int>& c_ref = vec;

ref.push_back(4);   // OK
c_ref.push_back(5); // ERROR
```
And any non-const reference to a const variable is not allowed. Furthermore, we can't also declare a non-const ref to a const ref.

But if you don't write `&`, C++ will treat it as a copy, by default:
```cpp
::std::vector<int> copy = c_ref; // copy is a copy of vec
copy.push_back(4);               // copy{1, 2, 3, 4}
```

When using `auto`, we need to explicitly specify `const` and `&`.

Updating elements in a `::std::vector`:
```cpp
int& front(std::vector<int>& vec) {
    // assuming vec.size() > 0
    return vec[0];
}

int main() {
    std::vector<int> numbers{1, 2, 3};
    front(numbers) = 4; // vec = {4, 2, 3}
    return 0;
}
```
Here is another example, combined with loops and deconstruction:
```cpp
vector<Student> students;
for (auto& [name, state, age]: students) {
    name = "Trump";
    state = "CA";
    age = 45;
}
```

**When to use ref?**

- Copying a big variable, we can use ref.
- If we don't need to modify it, use const ref.