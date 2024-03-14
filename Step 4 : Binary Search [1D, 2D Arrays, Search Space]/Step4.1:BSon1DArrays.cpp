// TC -> LOg N

// Recursion
int BinarySearchR(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
        return BinarySearchR(nums, low, mid - 1, target);
    else
        return BinarySearchR(nums, mid + 1, high, target);
}

int search(vector<int> &nums, int target)
{
    // Write your code here.
    int n = nums.size();
    return BinarySearchR(nums, 0, n - 1, target);
}

// Iterative
int search(vector<int> &nums, int target)
{
    // Write your code here.
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

/*
    Lower bound of x.
    T.C -> O(log N)
    if(arr[mid] >= x)
*/

int lowerBound(vector<int> arr, int n, int x)
{
    // Write your code here
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

// STL lower_boud

int lowerBound(vector<int> arr, int n, int x)
{
    // Write your code here
    // Using lower_bound to find the lower bound
    auto it = lower_bound(arr.begin(), arr.end(), x);

    // Calculating the index of the lower bound
    int index = it - arr.begin();

    return index;
}

// UPPER BOUND
int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

//  Search insert
int searchInsert(vector<int> &arr, int m)
{
    // Write your code here.
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int floor = -1;
    int ceil = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == x)
        {
            return make_pair(x, x);
        }
        else if (a[mid] < x)
        {
            floor = a[mid];
            low = mid + 1;
        }
        else
        {
            ceil = a[mid];
            high = mid - 1;
        }
    }

    return make_pair(floor, ceil);
}

/*
    Time Complexity : O(log(N))
    Space Complexity : O(1)

    where N is the length of array.
*/
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    int first = -1;
    int second = -1;

    // Find the first occurrence of k
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1; // continue searching on the left side for the first occurrence
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Reset low and high for the second binary search
    low = 0;
    high = n - 1;

    // Find the last occurrence of k
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            second = mid;
            low = mid + 1; // continue searching on the right side for the last occurrence
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return {first, second};
}

/*
    Time Complexity - O(LogN)
    Space Complexity - O(1)

    where N is the length of the array
*/

int firstOccurrence(vector<int> &arr, int n, int x)
{
    // Initialize start and end pointers
    int startIndex = 0, endIndex = n - 1;

    // Initialize a pointer for starting index of x
    int xStartIndex = -1;

    while (startIndex <= endIndex)
    {
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] >= x)
        {
            // If mid value is x, update index
            if (arr[mid] == x)
                xStartIndex = mid;

            // Search on left
            endIndex = mid - 1;
        }
        else
        {
            // Search on right
            startIndex = mid + 1;
        }
    }

    // Return xStartIndex;
    return xStartIndex;
}

int lastOccurrence(vector<int> &arr, int n, int x)
{
    // Initialize start and end pointers
    int startIndex = 0, endIndex = n - 1;

    // Initialize a pointer for starting index of x
    int xEndIndex = -1;

    while (startIndex <= endIndex)
    {
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] > x)
        {
            // Search on left
            endIndex = mid - 1;
        }
        else
        {
            // If mid value is x, update index
            if (arr[mid] == x)
                xEndIndex = mid;

            // Search on right
            startIndex = mid + 1;
        }
    }

    // Return xEndIndex;
    return xEndIndex;
}

int count(vector<int> &arr, int n, int x)
{
    // Initialize start and end position variables for x
    int xStartIndex, xEndIndex;

    xStartIndex = firstOccurrence(arr, n, x);

    // If x is not present
    if (xStartIndex == -1)
        return 0;

    xEndIndex = lastOccurrence(arr, n, x);

    // Total occurrences will be
    int count = xEndIndex - xStartIndex + 1;

    return count;
}

int search(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid points the target
        if (arr[mid] == k)
            return mid;

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                // element exists:
                high = mid - 1;
            }
            else
            {
                // element does not exist:
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted:
            if (arr[mid] <= k && k <= arr[high])
            {
                // element exists:
                low = mid + 1;
            }
            else
            {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

// Log N

bool searchInARotatedSortedArrayII(vector<int> &A, int key)
{
    // Write your code here.
    int low = 0;
    int high = A.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (A[mid] == key)
            return true;

        if (A[low] == A[mid] && A[mid] == A[high])
        {
            low++;
            high--;
            continue;
        }

        if (A[low] <= A[mid])
        {
            if (A[low] <= key && key <= A[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (A[mid] <= key && key <= A[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

/*
    Time Complexity: O(log(N))
    Space Complexity: O(1),

    where 'N' is the number of elements in the array.
*/

int findMin(vector<int> &arr)
{
    // Write your code here.
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

#include <bits/stdc++.h>

int findKRotation(vector<int> &arr)
{
    // Write your code here.
    int low = 0;
    int high = arr.size() - 1;

    int ans = INT_MAX;
    int index = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            index = low;
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            index = mid;
            high = mid - 1;
        }
    }
    return index;
}

/*
    Time Complexity  : O(log(N))
    Space Complexity : O(1)

    Where N is the total number of elements in the given array.
*/
int singleNonDuplicate(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}