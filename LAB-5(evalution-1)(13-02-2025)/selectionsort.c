#include <stdio.h>

int main() {
    int n, i, j, min, max, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n / 2; i++) {
        min = i;
        max = i;

        for (j = i + 1; j < n - i; j++) {
            if (arr[j] < arr[min]) min = j;
            if (arr[j] > arr[max]) max = j;
        }

        // Swap min to front
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

        // Fix max index if it was swapped with i
        if (max == i)
            max = min;

        // Swap max to end
        if (max != n - i - 1) {
            temp = arr[n - i - 1];
            arr[n - i - 1] = arr[max];
            arr[max] = temp;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
