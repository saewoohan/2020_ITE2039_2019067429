// 2019067429_ÇÑ½Â¿ì_12838
#include <stdio.h>

int arr[30001];


int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int i, key, j;
    for (i = 1; i < N; i++)
    {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for (int i = N - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
    return 0;
}