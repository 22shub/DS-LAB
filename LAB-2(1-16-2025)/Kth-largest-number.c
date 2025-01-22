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
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int p=0,l=0,arrl[n];
    arrl[l++]=arr[0];
    while(p++<n){
        if(arr[p]!=arr[p-1]){
            arrl[l++]=arr[p];
        }
    }
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if(k<=l)printf("the %dth largest term is %d", k, arrl[k-1]);
    else printf("Invalid input");
    return 0;
}