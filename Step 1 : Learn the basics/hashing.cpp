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



/*
    Time complexity: O( n )
    Space complexity: O( n )
    
    Where 'n' is the number of elements in the array.
*/

vector<int> getFrequencies(vector<int>& v) {
    
    // Declare a variable 'n' which is equal to the size 
    // of array 'v'.
    int n = v.size();
    
    // Declare a unordered map 'freq'
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        // Increment the frequency of the current element
        freq[v[i]]++;
    }

    // Initializing variables to determine
    // maximum frequency and minimum frequency element
    int maxFreq = 0, minFreq = n;
    int maxElement = 0, minElement = (int)1e9 + 1;
    
    // Traverse through map to find the elements.
    for (auto it : freq) {
        int count = it.second;
        int element = it.first;

        if (count > maxFreq) {
            // Found an element with frequency maximum among 
            // all elements found till now
            maxElement = element;
            maxFreq = count;
        }
        else if(count == maxFreq) {
            // Checking if the current element is smaller or not            
            maxElement = min(maxElement, element);
        }
        
        if (count < minFreq) {
            // Found an element with frequency maximum among 
            // all elements found till now
            minElement = element;
            minFreq = count;
        }
        else if(count == minFreq) {
            // Checking if the current element is smaller or not            
            minElement = min(minElement, element);
        }
    }
    
    vector<int> ans = {maxElement, minElement};
    return ans;
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

