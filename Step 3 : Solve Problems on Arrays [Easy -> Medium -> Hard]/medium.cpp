
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

    int countMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == element)
        {
            countMax++;
        }
    }

    if (countMax > (n / 2))
        return element;

    return -1;
}

// Kadane's algo.

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    // if (maxi < 0) maxi = 0;

    return maxi;
}

//  time complexity is O(n).
int bestTimeToBuyAndSellStock(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    int Maxprofit = 0;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prices[i]);
        Maxprofit = max(Maxprofit, prices[i] - mini);
    }
    return Maxprofit;
}

vector<int> alternateNumbers(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    int pos = 0;
    int neg = 1;

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            ans[pos] = a[i];
            pos += 2;
        }
        else
        {
            ans[neg] = a[i];
            neg += 2;
        }
    }
    return ans;
}

// C++ provides an in-built function called next_permutation() which directly returns the lexicographically next greater permutation of the input.
vector<int> nextGreaterPermutation(vector<int> &A)
{
    // Write your code here.
    next_permutation(A.begin(), A.end());
    return A;
}
vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1)
    {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}

vector<int> superiorElements(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    int maxi = INT_MIN;
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    sort(ans.begin(), ans.end());

    return ans;
}

/*
    Time Complexity: O( N )
    Space Complexity: O( 1 )

    Where 'N' is the length of the array 'A'.
*/

vector<int> superiorElements(vector<int> &a)
{
    int n = a.size();

    // Max element to the right.
    int maxElement = a[n - 1];

    vector<int> answer;

    // Last element is always a superior element.
    answer.push_back(a[n - 1]);

    // Iterate from right to left.
    for (int i = n - 2; i >= 0; i--)
    {

        // If current element is greater than all
        // the elements to the right of itself.
        if (a[i] > maxElement)
        {
            answer.push_back(a[i]);
            maxElement = a[i];
        }
    }

    // Return the 'answer' here.
    return answer;
}

/*
    Time Complexity: O(NlogN) + O(N), N = size of the given array.
Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).

Space Complexity: O(1), as we are not using any extra space to solve this problem.

*/

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    // sort the array:
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    // find longest sequence:
    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            // a[i] is the next element of the
            // current sequence.
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

/*
    Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
    SC - O(N)
*/

int longestSuccessiveElements(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    // put all the array elements into set:
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    // Find the longest sequence:
    for (auto it : st)
    {
        // if 'it' is a starting number:
        if (st.find(it - 1) == st.end())
        {
            // find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
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
