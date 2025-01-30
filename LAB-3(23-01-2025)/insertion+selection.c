#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i += 2) { 
        int piovet = i;
        for (int j = i + 2; j < n; j += 2) {
            if (arr[j] < arr[piovet]) {
                piovet = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[piovet];
        arr[piovet] = temp;
    }
    for (int i = 3; i < n; i += 2) { 
        int key = arr[i];
        int j = i - 2; 
        while (j >= 1 && arr[j] > key) {
            arr[j + 2] = arr[j];
                  j -= 2;
        }
        arr[j + 2] = key; 
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
         printf("%d ", arr[i]);
    }

    return 0;
}