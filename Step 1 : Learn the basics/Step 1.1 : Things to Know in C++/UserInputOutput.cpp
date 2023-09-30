#include<iostream>
using namespace std;

int main() {
	// Write your code here
	char x;
	std::cin >> x;
	if(x >= 97 && x <= 122) 
	{
		std::cout << 0 << '\n';
	}
	else if (x >= 65 && x <= 90) 
	{
		std::cout << 1 << '\n';
	}
	else
	{
		std::cout << -1 << '\n';
	}
}
