#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int l = 0;
    int arrl[n];
    arrl[l++] = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i - 1]){
            arrl[l++] = arr[i];
        }
    }
    printf("Unique elements: ");
    for(int i = 0; i < l; i++){
        printf("%d ", arrl[i]);
    }
    printf("\n");

    return 0;
}