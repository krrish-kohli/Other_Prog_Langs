/*
 * Tools used:
 * - Compiler: gcc
 * - Editor: VS Code
 * - Terminal / Shell: Mac Terminal / bash
 * - Websites: haskell.org, chatgpt.com, https://en.wikipedia.org/wiki/Quicksort
*/

#include "quicksort.h"


// Swap the values of two integers
static void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition the array around a pivot and returns the index where the pivot finally lands
static int partition(int *a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

// Recursively sorts the left and right halves around the pivot
static void quicksort_recursive(int *a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quicksort_recursive(a, low, pi - 1);
        quicksort_recursive(a, pi + 1, high);
    }
}

// This is the one to be called in main()
void quick_sort(int *a, int n) {  // Quick sort an array `a` with `n` elements in place.
    if (n > 1) {
        quicksort_recursive(a, 0, n - 1);
    }
}
