/*
 * Tools used:
 * - Compiler: gcc
 * - Editor: VS Code
 * - Terminal / Shell: Mac Terminal / bash
 * - Websites: haskell.org, gemini.com, https://en.wikipedia.org/wiki/Merge_sort, https://stackoverflow.com/questions/2550774/what-is-size-t-in-c
*/
#include "merge_sort.h"

// Function that merges two sorted halves of the array and uses 'temp' as temporary storage.
static void merge(int *a, int *temp, size_t left, size_t mid, size_t right) {
    size_t i = left;
    size_t j = mid + 1;
    size_t k = left;

    for (size_t l = left; l <= right; l++) {
        temp[l] = a[l];
    }

    while (i <= mid && j <= right) {
        if (temp[i] <= temp[j]) {
            a[k++] = temp[i++];
        } else {
            a[k++] = temp[j++];
        }
    }

    // If any elements are left in the first half, copy them over.
    while (i <= mid) {
        a[k++] = temp[i++];
    }

    // If any elements are left in the second half, copy them over.
    while (j <= right) {
        a[k++] = temp[j++];
    }
}

// Function that divides the array and calls merge.
static void merge_sort_recursive(int *a, int *temp, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        merge_sort_recursive(a, temp, left, mid);
        merge_sort_recursive(a, temp, mid + 1, right);

        merge(a, temp, left, mid, right);
    }
}

// The main merge_sort function that users call.
void merge_sort(int *a, size_t n) {
    // An array with 0 or 1 elements is already sorted.
    if (n < 2) {
        return;
    }

    // A temporary array on the stack.
    int temp[n];

    merge_sort_recursive(a, temp, 0, n - 1);
}