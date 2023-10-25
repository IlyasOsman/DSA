#include <iostream>
#include <vector>

/*
    Time Complexity: O(N*N)
    Space Complexity: O(1)

    Where 'N' is the length of an array.
*/

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int mini = arr[i];
        int minIndex = i;
        for (int j = i; j < n; j++) {
            if (mini > arr[j]) {
                mini = arr[j];
                minIndex = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    selectionSort(arr);
    
    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
