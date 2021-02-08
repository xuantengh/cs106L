#include <iostream>
#include <vector>

using std::vector;

template<typename InputIt, typename Pred>
int count_occurrences(InputIt begin, InputIt end, Pred pred) {
    int count = 0;
    for (auto it = begin; it != end; ++it) {
        count = pred(*it) ? count + 1 : count;
    }
    return count;
}

int main() {
    vector<int> v = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    int target = 1;
    auto is_equal = [&target](const int& val) -> bool {
        return val == target;
    };
    std::cout << target << " occurs " << count_occurrences(v.begin(), v.end(), is_equal) << " times." << std::endl;

    return 0;
}