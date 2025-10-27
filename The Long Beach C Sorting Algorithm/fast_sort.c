/*
 * Tools used:
 * - Compiler: gcc
 * - Editor: VS Code
 * - Terminal / Shell: Mac Terminal / bash
 * - Websites: chatgpt.com, https://en.wikipedia.org/wiki/Quicksort, https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/
*/

#include "fast_sort.h"
#include <stdlib.h>

const char first_name[] = "Krrish";
const char last_name[]  = "Kohli";

static const size_t insertion_cutoff = 16;

static void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void insertion_sort_range(int *a, size_t low, size_t high) {
    for (size_t i = low + 1; i <= high; ++i) {
        int key = a[i];
        size_t j = i;
        while (j > low && a[j - 1] > key) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = key;
    }
}


static void choose_pivot_median_to_end(int *a, size_t low, size_t high) {
    size_t mid = low + (high - low) / 2;

    if (a[mid] < a[low])  swap_int(&a[mid], &a[low]);
    if (a[high]  < a[low])  swap_int(&a[high],  &a[low]);
    if (a[high]  < a[mid]) swap_int(&a[high],  &a[mid]);
    swap_int(&a[mid], &a[high]);
}


static size_t partition(int *a, size_t low, size_t high) {
    int pivot = a[high];
    size_t i = low;
    for (size_t j = low; j < high; ++j) {
        if (a[j] <= pivot) {
            swap_int(&a[i], &a[j]);
            ++i;
        }
    }
    swap_int(&a[i], &a[high]);
    return i;
}


static void quicksort(int *a, size_t low, size_t high) {
    while (low < high) {
        // Small partitions: insertion sort is faster
        if (high - low + 1 <= insertion_cutoff) {
            insertion_sort_range(a, low, high);
            return;
        }

        // Choose a good pivot and partition
        choose_pivot_median_to_end(a, low, high);
        size_t p = partition(a, low, high);

        // Recurse on the smaller side; iterate on the larger
        size_t left_size;
        if (p > low) {
            left_size = p - low;
        } else {
            left_size = 0;
        }

        size_t right_size;
        if (p < high) {
            right_size = high - p;
        } else {
            right_size = 0;
        }


        if (left_size < right_size) {
            if (p > 0) quicksort(a, low, p - 1);
            low = p + 1;
        } else {
            if (p + 1 <= high) quicksort(a, p + 1, high);
            if (p == 0) return;
            high = p - 1;
        }
    }
}


void fast_sort(int *a, size_t n) {
    if (n < 2) return;
    quicksort(a, 0, n - 1);

    if (n <= insertion_cutoff) {
        insertion_sort_range(a, 0, n - 1);
    }
}