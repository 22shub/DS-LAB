#include <stdio.h>

int main(){
    int n,k=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
        if (arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            k++;
        }
    }
}

printf("Sorted array: ");
for (int i = 0; i < n; i++) {
    printf("%d\n ", arr[i]);
}
printf("the number of swaps are %d\n",k);
    return 0;
}
