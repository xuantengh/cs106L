# Special Member Functions

- default constructor
- copy constructor (deep copy)
- copy assignment (deep copy)
- destructor

## Member Initializer List

```cpp
template<typename T>
vector<T>::vector<T>(): _size(0), _capacity(K), _elem(new T[K]) { };
```

Initializer list calls the copy constructor of members (one step), while the default assignment manner calls default constructor first, then copy assignment (two steps). Therefore, using initializer list is more efficient way.

**Note: when writing assignment, be careful about self-reassignment**.


## Prevent Copies being Created

```cpp
class Vec {
    Vec(const Vec&) = delete;
};
```

## Rules

When there's a resource that our class uses that's not stored inside of our class (dynamically allocated memory), define custom constructor and destructors.

Remember to implement all of three: copy constructor, copy assignment and destructor.


