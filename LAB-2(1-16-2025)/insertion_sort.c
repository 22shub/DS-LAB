#include <stdio.h>

int main(){
    int n, operations = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            operations++; 
        }
        arr[j + 1] = key;
        operations++; 
    }

    printf("The Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Number of operations: %d\n", operations);
    return 0;
}
