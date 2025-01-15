#include<stdio.h>
int main()
{
      int n;
    printf("enter size of array");
    scanf("%d",& n);
    int a[n];
    printf("enter values of array");
    for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    for(int i=0;i<n/2;i++)
    {
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;


    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}