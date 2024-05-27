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

/*
    Time Complexity: O(N * log(sum(weights[]) – max(weights[]) + 1))
*/
#include <bits/stdc++.h>

int findDays(vector<int> &weights, int capacity)
{
    int load = 0;
    int days = 1;

    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > capacity)
        {
            days += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (findDays(weights, mid) <= d)
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

    Time Complexity: O(logN)
*/
int missingK(vector<int> vec, int n, int k)
{
    // Write your code here.
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int noOfMissingNo = vec[mid] - (mid + 1);

        if (noOfMissingNo < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low + k;
}

/*
    Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[])))
*/

bool canWePlace(vector<int> &stalls, int dist, int k)
{
    int lastCow = stalls[0];
    int cows = 1;
    int n = stalls.size();
    int cow = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastCow >= dist)
        {
            cows++;
            lastCow = stalls[i];
        }
        if (cows >= k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n - 1] - stalls[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (canWePlace(stalls, mid, k) == true)
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
    Time Complexity: O(N * log(sum(arr[])-max(arr[])+1))
*/

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int countPartitions(vector<int> &a, int maxSum)
{
    int n = a.size(); // size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++)
    {
        if (subarraySum + a[i] <= maxSum)
        {
            // insert element to current subarray
            subarraySum += a[i];
        }
        else
        {
            // insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k)
{
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    // Apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

/*
    Time Complexity: O(nlogn + klogn)
Space Complexity: O(n-1)+O(n-1)

*/
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size(); // size of array.
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    // insert the first n-1 elements into pq
    // with respective distance values:
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    // Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        // Find the maximum section
        // and insert the gas station:
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;

        // insert the current gas station:
        howMany[secInd]++;

        long double inidiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}

/*
    Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
*/

double median(vector<int> &a, vector<int> &b)
{
    // Write your code here.
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2)
        return median(b, a);

    int low = 0;
    int high = n1;

    int n = (n1 + n2);
    int left = (n + 1) / 2;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;

        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

/*

    Time Complexity: O(n X logm), where n = given row number, m = given column number.

*/
int lowerBound(vector<int> &matrix, int m, int x)
{

    int low = 0;
    int high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (matrix[mid] >= x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int index = -1;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int count = m - lowerBound(matrix[i], m, 1);
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }
    return index;
}