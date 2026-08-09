#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_largest(int *arr, int n) {
    int *max = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *max) {
            max = (arr + i);
        }
    }
    return *max;
}

void reverse_array(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int a = 10, b = 20;
    int arr[5] = {1, 5, 3, 9, 2};

    swap(&a, &b);
    printf("after swap: a=%d b=%d\n", a, b);

    printf("largest element: %d\n", find_largest(arr, 5));

    reverse_array(arr, 5);
    printf("reversed array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }

    return 0;
}