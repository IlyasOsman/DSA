#include <bits/stdc++>

long reverseBits(long n) {
    // Write your code here.
    long result = 0;
    int numBits = 32;

    for (int i = 0; i < numBits; i++) {
        result = (result << 1) | (n & 1); 
        n >>= 1;
    }

    return result;
}

int main(){
    int n {};
    std::cin >> n;
    reverseBits(n);

    return 0;
} 
