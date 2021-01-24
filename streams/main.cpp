#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // standard stream
    ::std::cout << "Hello World!" << ::std::endl;
    ::std::cout << 177 << ::std::endl;
    ::std::cout << "Mixed types: " << 114 << ::std::endl;
    // file stream
    ::std::ofstream out("out.txt", ::std::ofstream::out);
    out << 5 << ::std::endl;
    // stringstream
    ::std::string input = "5 seventy 2";
    ::std::istringstream i(input);
    int x; ::std::string y; int z;
    i >> x >> y >> z;
    ::std::cout << x << ' ' << y << ' ' << z << ::std::endl;
}