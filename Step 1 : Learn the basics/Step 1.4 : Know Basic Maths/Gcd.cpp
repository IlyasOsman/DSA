#include <bits/stdc++.h>

int calcGCD(int n, int m){
    // Write your code here.
    while(n>0 && m>0){

        if(m>n) m = m%n;

        else 

          n = n % m;

    }

    if(m == 0) return n;

    else  return m;

}

int main()
{
    int n, m {};
    std::cin >> n >> m;
    calcGCD(n);

    return 0;
}