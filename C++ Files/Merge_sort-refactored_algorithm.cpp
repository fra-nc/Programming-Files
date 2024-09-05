#include <iostream>
using namespace std;
// This program utilizes the merge sort algorithm to sort an array of integers in ascending order.

    // The merge sort algorithm is a divide and conquer algorithm that  recursively divides the array into two halves until each half has only one element.
    // The algorithm then merges the two halves back together in sorted order.
    // The time complexity of the merge sort algorithm is O(n log n).
    // The space complexity of the merge sort algorithm is O(n).
    // Function to merge two sorted arrays
    void
    merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
// Function to perform merge sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    // Declare size of array
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Array[" << i << "]: ";
        cin >> arr[i];
    }
    // print the unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // perform merge sort
    mergeSort(arr, 0, size - 1);
    // print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}