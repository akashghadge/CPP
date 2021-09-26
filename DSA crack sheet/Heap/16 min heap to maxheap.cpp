// A C++ program to convert min Heap to max Heap
#include <bits/stdc++.h>
using namespace std;

// to heapify a subtree with root at given index
void MaxHeapify(int arr[], int i, int n)
{
    int mini = i;
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;
    if (leftChild < n && arr[mini] < arr[leftChild])
    {
        mini = leftChild;
    }
    if (rightChild < n && arr[mini] < arr[rightChild])
    {
        mini = rightChild;
    }
    if (mini != i)
    {
        swap(arr[i], arr[mini]);
        MaxHeapify(arr, mini, n);
    }
}

// This function basically builds max heap
void convertMaxHeap(int arr[], int n)
{
    // Start from bottommost and rightmost
    // internal mode and heapify all internal
    // modes in bottom up way
    for (int i = (n - 2) / 2; i >= 0; --i)
        MaxHeapify(arr, i, n);
}

// A utility function to print a given array
// of given size
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
int main()
{
    // array representing Min Heap
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Min Heap array : ");
    printArray(arr, n);

    convertMaxHeap(arr, n);

    printf("\nMax Heap array : ");
    printArray(arr, n);

    return 0;
}
