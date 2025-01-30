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
    for (int i = 0; i < n - 1; i++) {
        int piovet = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[piovet]) {
          piovet = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[piovet];
        arr[piovet] = temp;
    }

    printf("The Sorted array is\n");
    for (int i = 0; i < n; i++) {
           printf("%d ", arr[i]);
    }

    return 0;
}