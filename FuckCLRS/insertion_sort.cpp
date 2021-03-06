#include <stdio.h>
#include <assert.h>

void PrintArray(int arr[], int len) {
    assert(len >= 0);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void InsertionSort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        // Find insertion point
        int key = arr[i];
        int j = i - 1;
        for (; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void InsertionSortRecursive(int arr[], int len) {
    if (len > 1) {
        InsertionSortRecursive(arr, len - 1);
        int key = arr[len - 1], i = len - 2;
        for ( ; i >= 0 && arr[i] > key; i--)
            arr[i + 1] = arr[i];
        arr[i + 1] = key;
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    PrintArray(arr, sizeof(arr) / sizeof(int));
    InsertionSortRecursive(arr, sizeof(arr) / sizeof(int));
    PrintArray(arr, sizeof(arr) / sizeof(int));
    return 0;
}
