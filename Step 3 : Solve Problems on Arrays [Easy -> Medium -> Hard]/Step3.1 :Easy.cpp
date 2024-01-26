// Largest Element in an array

#include <bits/stdc++.h>

using namespace std;

int largestElement(vector<int> &arr, int n)
{
    // Write your code here.
    int lElement = arr[0];
    ;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > lElement)
        {
            lElement = arr[i];
        }
    }
    return lElement;
}

/*
    Finding the second largest and second smallest
    Time complexity - O(N)
    Space complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(int n, vector<int> &a)
{
    int largetElement = a[0];
    int secondLargest = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > largetElement)
        {
            secondLargest = largetElement;
            largetElement = a[i];
        }
        else if (a[i] < largetElement && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }
    }
    return secondLargest;
}

int getSecondSmallest(int n, vector<int> &a)
{
    int smallestElement = a[0];
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < smallestElement)
        {
            secondSmallest = smallestElement;
            smallestElement = a[i];
        }
        else if (a[i] > smallestElement && a[i] < secondSmallest)
        {
            secondSmallest = a[i];
        }
    }
    return secondSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    // Write your code here.
    int sLargest = getSecondLargest(n, a);
    int secondSmallest = getSecondSmallest(n, a);

    return {sLargest, secondSmallest};
}

/*
    Check if array is sorted in non-decreasing order
    T.C - O(N)
    S.C - O(1)
*/

int isSorted(int n, vector<int> a)
{
    // Write your code here.
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int isSorted(int n, vector<int> a)
{
    int start = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < start)
        {
            return 0;
        }
        start = a[i];
    }
    return 1;
}

// Remove duplicate from array;
/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the length of the array.
*/

int removeDuplicates(vector<int> &arr, int n)
{
    // First pointer.
    int i = 0;

    // Second pointer traversing from 1 to n.
    for (int j = 1; j < n; j++)
    {
        //  If not duplicates increment first pointer and check again.
        if (arr[j] != arr[j - 1])
        {
            arr[i++] = arr[j];
        }
    }
    // Return length == (index of first pointer when second reaches end) + 1.
    return i + 1;
}

// Rotating by 1 to left

#include <bits/stdc++.h>
vector<int> rotateArray(vector<int> &arr, int n)
{
    // Write your code here.
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
}

// Rotate array by k to left
vector<int> rotateArray(vector<int> arr, int k)
{
    // Write your code here.
    int n = arr.size();
    k = k % n;

    int temp[k];

    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }

    return arr;
}

// optimal

vector<int> rotateArray(vector<int> arr, int k)
{
    // Write your code here.
    int n = arr.size();
    k = k % n;

    // Reverse the first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Reverse the remaining elements
    reverse(arr.begin() + k, arr.end());

    // Reverse the entire array
    reverse(arr.begin(), arr.end());

    return arr;
}

// MOve zeros to the end

vector<int> moveZeros(int n, vector<int> a)
{
    // Write your code here.
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return a;

    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }

    return a;
}

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

/*
    Time Complexity: O((N + M) * log(N + M))
    Space Complexity: O(N + M)

    N and M are the sizes of array 'a' and 'b' respectively.
*/
#include <set>
vector<int> sortedArray(vector<int> a, vector<int> b)
{

    int n = a.size(), m = b.size();
    // Using a min-heap to
    // store all distinct elements
    set<int> st;

    // Iterating over 'a'
    for (int i = 0; i < n; ++i)
    {
        st.insert(a[i]);
    }

    // Iterating over 'b'
    for (int i = 0; i < m; ++i)
    {
        st.insert(b[i]);
    }

    vector<int> unionArray;

    // Copying all elements
    // from the set to the vector
    for (const int &value : st)
    {
        unionArray.push_back(value);
    }

    return unionArray;
}

// TC - O(N + M)

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    vector<int> temp;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            if (temp.size() == 0 || temp.back() != a[i])
            {
                temp.push_back(a[i]);
            }

            i++;
        }
        else
        {
            if (temp.size() == 0 || temp.back() != b[j])
            {
                temp.push_back(b[j]);
            }

            j++;
        }
    }
    while (i < n)
    {
        if (temp.size() == 0 || temp.back() != a[i])
        {
            temp.push_back(a[i]);
        }

        i++;
    }
    while (j < m)
    {
        if (temp.size() == 0 || temp.back() != b[j])
        {
            temp.push_back(b[j]);
        }

        j++;
    }

    return temp;
}