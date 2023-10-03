#include <bits/stdc++.h>

bool palindrome(int n)
{
    // Write your code here
    int original_number { n };
    int reversed_number {};
    while(n > 0)
    {
        int digit = n % 10;           
        reversed_number = (reversed_number * 10) + digit;
        n /= 10;
    }
    if(reversed_number == original_number)
    {
        return true;
    }
    return false;
}

int main()
{
    int n {};
    std::cin >> n;
    palindrome(n);

    return 0;
}