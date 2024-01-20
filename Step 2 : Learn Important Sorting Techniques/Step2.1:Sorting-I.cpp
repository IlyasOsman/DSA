#include <iostream>
#include <vector>

/*
    Time Complexity: O(N*N)
    Space Complexity: O(1)

    Where 'N' is the length of an array.
*/
using namespace std;

void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int mini = arr[i];
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (mini > arr[j])
            {
                mini = arr[j];
                minIndex = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}

/*
    Time Complexity : O(n ^ 2)
    Space Complexity : O(1)
    where n is size of the input array
*/
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // If jth element is greater than 'j + 1' th element
            // swap them
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// insertion sort
void insertionSort(int arr[], int n)
{
    // write your code here
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

int main()
{
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    selectionSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    return 0;
}
