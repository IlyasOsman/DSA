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
