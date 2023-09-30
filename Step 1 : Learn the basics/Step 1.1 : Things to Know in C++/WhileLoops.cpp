#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n {};
	cin >> n;
	int sum_of_even {};
	int sum_of_odd {};
	while(n > 0) {
		int digit = n % 10;	
		if(digit % 2)
		{
			sum_of_odd += digit;
		}
		else
		{
			sum_of_even += digit;
		}

		n /= 10;
	}
	
	cout <<  sum_of_even << " " << sum_of_odd;
	return 0;
}
