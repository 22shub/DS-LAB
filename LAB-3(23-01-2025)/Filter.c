#include <stdio.h>
int filter(float a[7][7], int n, int m) {
    int sum = 0;
    for (int i = n - 1; i <= n + 1; i++) {
        for (int j = m - 1; j <= m + 1; j++) {
            sum = sum + a[i][j];
        }
    }
    return sum;
}
int main() {
    float a[7][7];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            a[i][j] = (i+1)*(j+1);//random entry. You can change it to scanf("%d", &a[i][j]);
        }
    }
    printf("Original matrix is:\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%.0f ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i < 6; i++) {
        for (int j = 1; j < 6; j++) {
            a[i][j] = filter(a, i, j)/9.0;
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