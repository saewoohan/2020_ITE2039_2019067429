// 2019067429_ÇÑ½Â¿ì_12838
#include <stdio.h>
#include <stdlib.h>

int arr[100001];

void Merge(int l, int m, int r) {
    int n1, n2;

    n1 = m - l + 1;
    n2 = r - m;

    int* arr1 = (int*)malloc(sizeof(int) * n1);
    int* arr2 = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        arr2[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = (l + r - 1) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        Merge(l, m, r);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(0, N - 1);

    for (int i = N - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
    return 0;
}