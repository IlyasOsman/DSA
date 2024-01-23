#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{

    vector<int> temp;

    int left = low;

    int right = mid + 1;

    while (left <= mid && right <= high)
    {

        if (arr[left] <= arr[right])
        {

            temp.push_back(arr[left]);

            left++;
        }
        else
        {

            temp.push_back(arr[right]);

            right++;
        }
    }

    while (left <= mid)
    {

        temp.push_back(arr[left]);

        left++;
    }

    while (right <= high)
    {

        temp.push_back(arr[right]);

        right++;
    }

    for (int i = low; i <= high; i++)
    {

        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{

    if (low < high)
    {

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Quick sort
// Time.C - O(N log N)
// Space.C O(1)

/*
    The function is called with the parameters:
    quickSort(input, 0, size - 1);

*/
#include <bits/stdc++.h>

int partitionArray(int input[], int start, int end)
{
    // Write your code here
    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        while (i <= end && input[i] <= input[pivot])
        {
            i++;
        }
        while (j >= start + 1 && input[j] > input[pivot])
        {
            j--;
        }
        if (i < j)
        {
            swap(input[i], input[j]);
        }
    }

    swap(input[start], input[j]);
    return j;
}

void quickSort(int input[], int start, int end)
{
    if (start < end)
    {
        int partition = partitionArray(input, start, end);

        quickSort(input, start, partition - 1);
        quickSort(input, partition + 1, end);
    }
}

int main()
{

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}