#include<stdio.h>
int main(){
    int n,k;
    printf("enter the length of array\n");
    scanf("%d",&n);
      printf("enter the elements of array\n");
      float arr[n];
      for(int i=0;i<n;i++){
        scanf("%f",& arr[i]);
      }
      printf("enter length of average\n");
      scanf("%d",&k);
      float avg[n-k+1];
      for(int i=0;i<=n-k;i++)
      {
        float l = 0;
        for(int j=0;j<k;j++)
        {
        l=l+(arr[i+j]);
        }
        avg[i]=l/k;
        l=0;

      }
      printf("the moving array average is");
      for(int i=0;i<=n-k;i++)
      {
        printf("%f\n",avg[i]);
      }
      return 0;
}