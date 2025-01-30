#include <stdio.h>

int weighted_filter (float a[7][7], int n, int m,int b[3][3]) {
    float sum = 0;
    int i=0,j=0,l=m;
    while(n-1<=n+1&&i<3){
        while(m-1<=m+1&&j<3){
            sum = sum+ (a[n-1][m-1]*b[i][j++]);
            m++;
    }
    m=l;
    j=0;
    i++;
    n++;
    }
    return sum;
}
int main() {
    float a[7][7];
    int filter[3][3];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            a[i][j] = (i+1)*(j+1);//random entry. You can change it to scanf("%f", &a[i][j]);
        }
    }
    printf("enter values of the filter\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&filter[i][j]);
    }
    }
    printf("Original matrix is:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%.f ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            a[i][j] = weighted_filter(a, i, j,filter)/9.0;
        }
    }
    printf("Modified matrix is:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
    }