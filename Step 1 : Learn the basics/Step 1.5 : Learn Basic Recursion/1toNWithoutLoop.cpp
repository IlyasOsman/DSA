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
    long long result { 1 };
    long long cnt { 1 };

    vector<long long> ans;

    while(result <= n / cnt)
    {
        result *= cnt;
        cnt++;

        ans.push_back(result);    
    }
    return ans;
}


vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    int start = 0;
    int end = n - 1;

    while (start < end) {
        // Swap the elements at the start and end indices
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;

        // Move the start index forward and the end index backward
        start++;
        end--;
    }

    return nums;
}


 /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    where n is the size of the input array.
*/

// Function to reverse the elements of the given array 'nums'.
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Create a new vector to store the reversed elements.
    vector<int> reversedArray(n);

    // Traverse the original array in reverse order and store the elements in the new array.
    for (int i = n - 1; i >= 0; i--)
    {
        reversedArray[n - i - 1] = nums[i];
    }

    // Returning the reversed array.
    return reversedArray;
}
 

bool isPalindromeH(string& str, int start, int end) {
    // Base case: If the string has 0 or 1 character, it's a palindrome.
    if (start >= end) {
        return true;
    }

    // Compare the characters at the outer ends of the string.
    if (str[start] == str[end]) {
        // If they are the same, check if the substring inside is a palindrome.
        return isPalindromeH(str, start + 1, end - 1);
    } else {
        // If the characters are different, it's not a palindrome.
        return false;
    }
}

bool isPalindrome(string& str) {
    int start = 0;
    int end = str.length() - 1;
    return isPalindromeH(str, start, end);
}


// Optimal palindrome




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