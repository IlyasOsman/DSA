
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