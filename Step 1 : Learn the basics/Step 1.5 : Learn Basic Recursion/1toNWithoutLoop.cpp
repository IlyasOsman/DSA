#include <bits/stdc++.h>

std::vector<int> printNos(int x)
{
    // Write Your Code Here
    std::vector<int> result;

    std::function<void(int)> recursivePrint = [&](int i)
    {
        if (i > x)
        {
            return;
        }

        result.push_back(i);
        recursivePrint(i + 1);
    };

    recursivePrint(1);

    return result;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> numbers = printNos(n);

    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    return 0;
}