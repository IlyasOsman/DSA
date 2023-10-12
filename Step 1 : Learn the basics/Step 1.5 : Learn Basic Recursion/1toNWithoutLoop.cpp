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



vector<string> printNTimes(int n) {
	// Write your code here.
	if (n == 0) {
        return vector<string>();
    }

	string string_to_print = "Coding Ninjas";	
	vector<std::string> result = printNTimes(n - 1);
	result.push_back(string_to_print);

	return result;
}


vector<int> printNos(int x) {
    // Write Your Code Here
    if(x == 0)
    {
        return vector<int> ();
    }

    vector<int> result = printNos(x - 1);
    result.insert(result.begin(), x);

    return result;
}

long long sumFirstN(long long n) {
    // Write your code here.
    return (n * (n + 1)) / 2;
}

vector<long long> factorialNumbers(long long n) {
    if (n == 1) {
        return std::vector<long long>{1};
    }
    if (n == 2) {
        return std::vector<long long>{1, 2};
    }

    std::vector<long long> result = factorialNumbers(n - 1);

    for (long long i = 2; i <= n; i++) {
        if (n % i == 0) {
            result.push_back(i);
        }
    }

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