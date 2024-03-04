
int #include<bits / stdc++.h> using namespace std;

vector<int> majorityElement(vector<int> v)
{
    int n = v.size(); // size of the array

    int cnt1 = 0, cnt2 = 0; // counts
    int el1 = INT_MIN;      // element 1
    int el2 = INT_MIN;      // element 2

    // applying the Extended Boyer Moore's Voting Algorithm:
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && el2 != v[i])
        {
            cnt1 = 1;
            el1 = v[i];
        }
        else if (cnt2 == 0 && el1 != v[i])
        {
            cnt2 = 1;
            el2 = v[i];
        }
        else if (v[i] == el1)
            cnt1++;
        else if (v[i] == el2)
            cnt2++;
        else
        {
            cnt1--, cnt2--;
        }
    }

    vector<int> ls; // list of answers

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == el1)
            cnt1++;
        if (v[i] == el2)
            cnt2++;
    }

    int mini = int(n / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    sort(ls.begin(), ls.end()); // TC --> O(2*log2) ~ O(1);

    return ls;
}

// Time Complexity: O(NlogN)+O(N2), where N = size of the array.

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        // remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

// 4 sum
/*
    Time Complexity : O( N^3  ),
    Space complexity: O( 1 )

    Space Complexity: O(no. of quadruplets), This space is only used to store the answer.
    We are not using any extra space to solve this problem. So, from that perspective,
    space complexity can be written as O(1).

    Where 'N' is the length of the array.

*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // Write your code here
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        // Remove duplicate
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];

                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    // skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
}

/*
Time Complexity: O(N), where 'N' is the length of 'Arr'.

Space Complexity: O(N), where 'N' is the length of 'Arr'.
*/

#include <bits/stdc++.h>

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mpp;
    int sum = 0;
    int longest = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            longest = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                longest = max(longest, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return longest;
}

#include <bits/stdc++.h>

// O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
int subarraysWithSumK(vector<int> a, int b)
{
    // Write your code here
    int xr = 0;
    map<int, int> mpp;
    int count = 0;
    mpp[xr]++;
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        // xoring each
        xr = xr ^ a[i];
        // Looking for b. previous occurrence of x.
        int x = xr ^ b;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}

// Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size(); // size of the array

    // sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

// Time Complexity: O(N), where N = the size of the given array.

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    // S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    // Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    // Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    //  Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

///  maximum product subarray

#include <bits/stdc++.h>

int subarrayWithMaxProduct(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int ans = INT_MIN;
    int pref = 1;
    int suf = 1;

    for (int i = 0; i < n; i++)
    {
        if (pref == 0)
            pref = 1;
        if (suf == 0)
            suf = 1;
        pref *= arr[i];
        suf *= arr[n - i - 1];
        ans = max(ans, max(pref, suf));
    }
    return ans;
}

// count inversion NlogN
int merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    int count = 0;
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            count += (mid - left) + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }

    return count;
}

int mergeSort(vector<int> &a, int low, int high)
{
    int mid = (low + high) / 2;
    int count = 0;
    if (low >= high)
        return count;

    count += mergeSort(a, low, mid);
    count += mergeSort(a, mid + 1, high);
    count += merge(a, low, mid, high);

    return count;
}
int numberOfInversions(vector<int> &a, int n)
{
    // Write your code here.
    int low = 0;
    int high = n - 1;
    return mergeSort(a, low, high);
}