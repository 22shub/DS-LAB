#include <stdio.h>
int count = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] >= pivot) j--;
        if (i >= j) break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        count++;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int main() {
    int n;
    printf("Enter the size : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    count = 0;
    quicksort(arr, 0, n - 1);
    printf("Number of pivot operations: %d\n", count);
    return 0;
}