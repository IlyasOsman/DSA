#include<bits/stdc++.h>
using namespace std;



int fibonacci(int n) {
        if (n == 1 || n == 2) {
                return 1;
        }

        int fib_n_minus_1 = 1; // Initialize F(n-1)
        int fib_n_minus_2 = 1; // Initialize F(n-2)
        int fib_n = 0;         // Initialize F(n)

        for (int i = 3; i <= n; ++i) { 
                fib_n = fib_n_minus_1 + fib_n_minus_2;

                // Update F(n-1) and F(n-2) for the next iteration
                fib_n_minus_2 = fib_n_minus_1;
                fib_n_minus_1 = fib_n;
        }

        return fib_n;
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin >> n;
        std::cout << fibonacci(n) << '\n';
        return 0;
}