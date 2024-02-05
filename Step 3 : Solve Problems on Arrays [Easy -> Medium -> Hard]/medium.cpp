
#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    where N is the number of elements
    of the array.
*/
#include <unordered_map>
int majorityElement(vector<int> v)
{
    // n is the number of elements
    // in the array
    int n = v.size();

    // Hashmap to store key-value pair
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i)
    {
        if (freq.count(v[i]))
        {
            // v[i] exists
            // Only increase the frequency
            ++freq[v[i]];
        }
        else
        {
            // Doesn't exist
            freq[v[i]] = 1;
        }
    }

    for (auto &p : freq)
    {
        int value = p.first, cnt = p.second;
        // value's frequency in the array
        // is cnt

        if (cnt > n / 2)
        {
            return value;
        }
    }
}

// Using moore's voting algo.
int majorityElement(vector<int> v)
{
    // Write your code here
    int n = v.size();
    int count = 0;
    int element;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            element = v[i];
        }
        else if (v[i] == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == element)
        {
            count1++;
        }
    }

    if (count1 > (n / 2))
        return element;

    return -1;
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
