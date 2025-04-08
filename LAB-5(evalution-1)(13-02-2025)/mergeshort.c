#include <stdio.h>

int main() {
    int arr[100]; 
    int n;

    printf("Enter the size of the array: ");  
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int u = 0; u < n; u++) {
        scanf("%d", &arr[u]);
    }

    int temp[n];  // Temporary array for merging

    int size, left, mid, right;
    for (size = 1; size < n; size *= 2) {
        for (left = 0; left < n - 1; left += 2 * size) {
            mid = left + size;
            right = left + 2 * size;

            if (mid > n) mid = n;
            if (right > n) right = n;

            // Merge subarrays arr[left..mid-1] and arr[mid..right-1]
            int i = left;
            int j = mid;
            int k = left;

            while (i < mid && j < right) {
                if (arr[i] <= arr[j]) {
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }

            while (i < mid) temp[k++] = arr[i++];
            while (j < right) temp[k++] = arr[j++];

            // Copy merged subarray back to original array
            for (i = left; i < right; i++) {
                arr[i] = temp[i];
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
