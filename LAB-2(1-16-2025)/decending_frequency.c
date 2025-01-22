#include <stdio.h>

int main()
{
    int n, k = 0, l = 0, m = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int freq[n], count[n];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    m = arr[0];
    while (k < n) {
        freq[l] = 1;
        count[l] = arr[k];
        while (k + 1 < n && arr[k] == arr[k + 1]) {
            freq[l]++;
            k++;
        }
        k++;
        l++;
    }

    for (int i = 0; i < l; i++) {
        printf("\n%d occurs %d times", count[i], freq[i]);
    }
    printf("\n");
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < l; j++) {
            if (freq[i] < freq[j]) {
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;
                temp = count[i];
                count[i] = count[j];
                count[j] = temp;
            }
        }
    }
    printf("The elements in decreasing frequency order are: ");
    for (int i = 0; i < l; i++) {
        printf("%d\n", count[i]);
    }
    return 0;
}