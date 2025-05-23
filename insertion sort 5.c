#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {45, 12, 89, 33, 7, 62, 28, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array: ");
    printArray(arr, n);
    insertionSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}

/* output:
Unsorted Array: 45 12 89 33 7 62 28 5 
Sorted Array: 5 7 12 28 33 45 62 89  */
