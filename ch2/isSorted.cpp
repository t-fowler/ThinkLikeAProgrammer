#include <iostream>
#include <cassert>

bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {8, 10, 9, 7, 4, 5, 2, 1, 3, 6};
    int sorted[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    int sorted_to_length_five[] = {1, 2, 3, 4, 5, 0};
    int single_element[] = {1};
    int empty_array[] = {};

    assert(!isSorted(arr, 10));
    assert(isSorted(sorted, 11));
    assert(isSorted(empty_array, 0));
    assert(isSorted(sorted_to_length_five, 5));
    assert(isSorted(single_element, 1));

    std::cout << "Passed all tests.\n";
}