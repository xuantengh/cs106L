// using C++17 standard
#include <iostream>
#include <string>
using std::string;

struct Student {
    string name;
    string state;
    int age;
};

int main() {
    auto p = ::std::make_pair("s", 5);
    auto [s, i] = p;
    ::std::cout << s << ' ' << i << ::std::endl;
    Student ss = {"Trump", "CA", 20};
    ::std::tuple<string, int, int> query_result = {"Biden", 46, 2020};
    ::std::cout << ::std::get<0>(query_result) << ::std::endl;
    return 0;
}