#include<iostream>

using namespace std;

void printSquare(int n) 
{
    // code here
    for(int row {}; row < n; row++)
    {
        for(int column {}; column < n - 1; column++)
        {
            cout << "*" << ' ';
        }
        cout << "*" << '\n';
    }
}

void printTriangle(int n) {
    // code here
    for(int row {}; row < n; row++)
    {
        for(int column { row }; column >= 0; column--)
        {
            cout << "*" << ' ';
        }
        
        cout << '\n';
    }
}


void printTriangle1(int n) {
    // code here
    for (int row {}; row <= n; row++)
    {
        for(int column { 1 }; column <= row; column++)
        {
            cout << column << ' ';
        }
        cout << '\n';
    }
}

int main()
{
int n;
cin >> n;
printSquare(n);
return 0;
}