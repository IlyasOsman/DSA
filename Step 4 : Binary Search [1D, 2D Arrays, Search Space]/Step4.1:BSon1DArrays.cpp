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

/*
    Time Complexity: O(log 'n')
    Space Complexity: O(1)

    Where 'n' is the number of elements
*/

int findPeakElement(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();

    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1;
    int high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid] < arr[mid + 1])
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

// LOg n

int floorSqrt(int n)
{
    // Write your code here.
    int low = 1;
    int high = n;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        long long square = (mid * mid);

        if (square <= (long long)(n))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

/*
    Time Complexity: O( sqrt(n) )
    Space Complexity: O( 1 )

    Where 'n' is the given number.
*/

// Function to find the square root of 'n'
int floorSqrt(int n)
{

    // Corner case
    if (n == 0)
    {
        return 0;
    }

    // Take 'ans' variable to store the square root of given number 'n'
    int ans = 1;

    // Run loop while square of 'ans' is less than equal to 'n'
    while (ans <= (n / ans))
    {
        // Increament 'ans' by 1
        ans++;
    }

    // Return 'ans'-1
    return (ans - 1);
}

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/*
    Koko eating banana
    Time complexity = O(n log n)
    S.C = O(N)
*/

int calculateHourly(vector<int> &v, int m)
{
    int h = 0;
    for (int i = 0; i < v.size(); i++)
    {
        h += ceil((double)(v[i]) / m);
    }
    return h;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    // Write Your Code Here
    int high = *max_element(v.begin(), v.end());
    int low = 1;

    sort(v.begin(), v.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int totalHours = calculateHourly(v, mid);

        if (totalHours <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

/*
    Time Complexity: O( n * log ( d ) )
    Space Complexity: O( 1 )

    where n denotes the number of roses and d denotes the maximum value of the array.
*/

bool possible(vector<int> &arr, int k, int day, int m)
{
    int noOfBouPossible = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {
            noOfBouPossible += (count / k);
            count = 0;
        }
    }
    noOfBouPossible += (count / k);

    return noOfBouPossible >= m;
}

int roseGarden(vector<int> arr, int k, int m)
{
    // Write your code here
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int n = arr.size();

    if ((k * m) > n)
        return -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (possible(arr, k, mid, m))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

/*
    Time Complexity: O(log(max(arr[]))*N)
*/

int sumDivisors(vector<int> &arr, int divisor)
{
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)(arr[i]) / divisor);
    }
    return sum;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    // Write your code here.
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (sumDivisors(arr, mid) <= limit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}