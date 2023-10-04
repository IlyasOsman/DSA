#include <bits/stdc++.h>

int sumOfAllDivisors(int n){
	// Write your code here.
	  int totalSum = 0;

    for (int i = 1; i <= n; i++) {
        int divisorSum = 0;

        for (int j = 1; j*j <= i; j++) {
            if (i % j == 0) {
                divisorSum += j;

                if (i / j != j) {
                    divisorSum += i / j;
                }
            }
        }
        totalSum += divisorSum;
    }

    return totalSum;
}

//
// int sumOfAllDivisors(int n){
// 	// Write your code here.
// 	  int totalSum {};
// 	  int i { 1 };
// 	  while(i <= n)
// 	  {
// 		  totalSum += (i * ( n / i));
// 		  i++;
// 	  }

// 	  return totalSum;
// }

int main()
{
    int n;
    std::cin >> n;

    sumOfAllDivisors(n);

    return 0;
}