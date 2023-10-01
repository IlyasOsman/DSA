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

void printTriangle2(int n) {
// code here
for (int row { 1 }; row <= n; row++)
{
for(int column { 1 }; column <= row; column++)
{
cout << column << ' ';
}
cout << '\n';
}
}


void printTriangle3(int n) {
// code here
for(int  row { 1 }; row <= n; row++)
{
for(int column { 1 }; column <= row; column++)
{
cout << row << " ";
}
cout << '\n';
}
}

void printTriangle(int n) {
// code here
for(int row {}; row < n; row++)
{
for(int column { n }; column > row; column-- )
{
    cout << '*' << ' ';
}

cout << '\n';
}
}

void printTriangle(int n) {
// code here
for(int row { 0 }; row < n; row++)
{
    for(int column { 1 }; column < n - row + 1; column++)
    {
        cout << column << ' ';
    }
    cout << endl;
}
}

void printTriangle(int n) {
// code here
for(int row { 0 }; row < n; row++)
{
    for(int space { 0 }; space < n - row -1; space++ )
    {
        cout << ' ';
    }
    for(int star { 0 }; star < 2 * row + 1; star++)
    {
        cout << '*';
    }
    for(int space { 0 }; space < n - row - 1; space++ )
    {
        cout << ' ';
    }
    cout << '\n';
}
}

void printTriangle(int n) {
    // code here
    for(int row { }; row < n; row++)
    {
        for(int space { }; space < row; space++ )
        {
            cout << ' ';
        }
        for(int star { }; star < 2*n - (2 * row + 1); star++)
        {
            cout << '*';
        }
        for(int space { }; space < row; space++ )
        {
            cout << ' ';
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