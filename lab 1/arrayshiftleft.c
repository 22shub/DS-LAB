#include<stdio.h>
int main(){
        int n;
    printf("enter size of array");
    scanf("%d",& n);
    int a[n+2];
    printf("enter values of array");
    for(int i=1;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i--)
    {
        a[i]=a[i+1];
        a[i+1]=0;
    }
        for(int i=0;i<n+1;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}