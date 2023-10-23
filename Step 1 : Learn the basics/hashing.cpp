#include <bits/stdc++.h>


std::vector<int> countFrequency(int n, int x, std::vector<int> &nums) {
    std::vector<int> frequencies(n, 0);

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (num >= 1 && num <= n) {
            frequencies[num - 1]++;
        }
    }

    return frequencies;
}


int main() {
    int n, x;
    std::cin >> n >> x; // Input the values of n and x

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i]; // Input the elements of the vector nums
    }

    std::vector<int> result = countFrequency(n, x, nums);

    // You can use the result vector for further processing or simply return the frequencies.
    return 0;
}

