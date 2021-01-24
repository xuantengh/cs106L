# Streams
TL;DR

A Stream  is an abstraction for input/output. It convert between the string representation of data and data itself.

```cpp
::std::cout << "Hello World!" << ::std::endl;
::std::cout << 177 << ::std::endl;
::std::cout << "Mixed types: " << 114 << ::std::endl;
```

## Types of Streams

Here are 4 main types of streams: `istream`, `ostream`, `iostream` and `stringstream`, distinguished by the destination of the stream.

### Ostreams

`::std::ostream` means output stream, including `::std::cout`, and `::std::ofstream` (output file stream) and etc.

```cpp
::std::ofstream out("out.txt", ::std::ofstream::out);
out << 5 << ::std::endl;
```

### Istreams

To read the entire line, use:
```cpp
 getline(istream& stream, string& line);
```

`>>` reads up to the next whitespace character and *does not* go past that whitespace, while `getline()` reads up to the next delimiter (by default, `\n`), and *does* go past that delimiter.

### IOstreams

`::std::iostream` is both `istream` & `ostream`.

### StringStreams

```cpp
::std::string input = “5 seventy 2”;

::std::istringstream i(input);
int x; ::std::string y; int z;
i >> x >> y >> z;
::std::cout << z << ::std::endl;
```

Stringstreams could be exploited to format output in C++.

## String Internals

- Buffer
    
    We can use the streams as a buffer, since outputing separate characters are time consuming.
    Empty the buffer so far by:
    ```cpp
    stream << ::std::flush;
    ```
- State Bits

    ![qv3fozT2HYrJ8DX](https://i.loli.net/2021/01/24/qv3fozT2HYrJ8DX.png)
    ```cpp
    while (true) {
        stream >> temp;
        if (stream.fail()) break;
        if (!stream) break; // same thing
    }
    ```
    Or use a very common read loop:
    ```cpp
    while (stream >> temp) {
        // do something here
    }
    ```
- Chaining

    `<<` and `>>` are actually functions:
    ```cpp
    std::ostream& operator<<(std::ostream& out, const std::string& s);
    std::istream& operator>>(std::string& s);
    ```