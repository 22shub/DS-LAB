#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        if((i+1)%2==0){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]&&(j+1)%2==0){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    }
    printf("The even position sorted array is:\n ");
    for (int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}