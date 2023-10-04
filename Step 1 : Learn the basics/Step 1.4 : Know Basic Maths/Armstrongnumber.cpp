#include <bits/stdc++.h>

bool checkArmstrong(int n){
	//Write your code here
	int original_n { n };
    int count {};
    int arms {};
    int temp { n };

    while (temp > 0) {
        temp /= 10;
        count++;
    }

    temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        arms += pow(digit, count);
        temp /= 10;
    }

    return arms == original_n;	
}

int main()
{
    int n;
    std::cin >> n;

    checkArmstrong(n);

    return 0;
}