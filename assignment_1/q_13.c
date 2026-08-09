#include <stdio.h>
#include <stdlib.h>

int sum(int *arr, int n) {
    int s = 0;
    for(int i = 0; i < n; i++)
        s += arr[i];
    return s;
}

float avg(int *arr, int n) {
    return (float)sum(arr, n) / n;
}

int largest(int *arr, int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

int smallest(int *arr, int n) {
    int min = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] < min)
            min = arr[i];
    return min;
}

int main() {
    int n, i;
    int *arr;

    printf("enter number of elements: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    printf("enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("sum = %d\n", sum(arr, n));
    printf("avg = %.2f\n", avg(arr, n));
    printf("largest = %d\n", largest(arr, n));
    printf("smallest = %d\n", smallest(arr, n));

    free(arr);

    return 0;
}