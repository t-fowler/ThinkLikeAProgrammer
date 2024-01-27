#include <cassert>
#include <iostream>
#include <map>

namespace TLAP {

// 3-7
// Pre-condition: size > 0
int mode(int arr[], size_t size) {
    std::map<int, int> histogram;
    for (int idx = 0; idx < size; idx++) {
        histogram[arr[idx]]++;
    }

    int most_frequent = 0;
    int highest_frequency = 0;
    for (const auto& [value, frequency] : histogram) {
        if (frequency > highest_frequency) {
            most_frequent = value;
            highest_frequency = frequency;
        }
    }
    return most_frequent;
}

} // namespace TLAP

int main() {
    int test1[10] = {0, 1, 5, 5, 1, 3, 5, 2, 0, 10,};
    int test2[10] = {0, 1, 675, 675, 1, 3, 675, 2, 0, 10,};
    int test3[1] = {999};
    int test4[5] = {1, 1, 2, 2, 10};
    
    assert(TLAP::mode(test1, 10) == 5);
    assert(TLAP::mode(test2, 10) == 675);
    assert(TLAP::mode(test3, 1) == 999);
    assert(TLAP::mode(test4, 5) == 1);

    std::cout << "Passed all tests.\n";
}