#include <bits/stdc++.h>

int countDigits(int n){
	// Write your code here.
	int count {};
	int cur { n };
	while(cur > 0)
	{
		int digit = cur % 10;
		if(digit != 0)
		{
			count+= (n % digit==0);
		}
		
		cur /= 10;		
	}
	return count;
}

int main(){
    int n {};
    std::cin >> n;
    countDigits(n);

    return 0;
}