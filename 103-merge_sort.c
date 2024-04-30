#include <stdio.h>
#include <stdlib.h>

void merge(int *left, size_t left_size, int *right, size_t right_size, int *array);
void merge_sort(int *array, size_t size);

void merge_sort(int *array, size_t size) {
    if (size <= 1) {
        return;
    }

    size_t mid = size / 2;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size - mid) * sizeof(int));

    for (size_t i = 0; i < mid; i++) {
        left[i] = array[i];
    }
    for (size_t i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    printf("Merging...\n");
    printf("[left]: ");
    for (size_t i = 0; i < mid; i++) {
        printf("%d ", left[i]);
    }
    printf("\n");
    printf("[right]: ");
    for (size_t i = 0; i < size - mid; i++) {
        printf("%d ", right[i]);
    }
    printf("\n");

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(left, mid, right, size - mid, array);

    free(left);
    free(right);
}

void merge(int *left, size_t left_size, int *right, size_t right_size, int *array) {
    size_t i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    while (i < left_size) {
        array[k++] = left[i++];
    }

    while (j < right_size) {
        array[k++] = right[j++];
    }

    printf("[Done]: ");
    for (size_t i = 0; i < left_size + right_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
