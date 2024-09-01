// C Program to Sort an Array in Ascending Order using Selection Sort
#include <stdio.h>

// Function to perform selection sort
void selectionSort(int arr[], int len) {

    for (int i = 0; i < len - 1; i++) {
        int min_idx = i;

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("unsorted array:");
    for(int i=0;i<len;i++){
    printf("%d ",arr[i]);
    }
    selectionSort(arr, len);

    printf("\nSorted array: ");
    for (int i = 0; i <len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
