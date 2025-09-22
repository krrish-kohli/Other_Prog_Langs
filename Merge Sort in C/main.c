#include <stdio.h>
#include "merge_sort.h"

void print_array(int *a, int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}");
}

int main(void) {
    printf("CECS 342 Assignment 3\n");
    printf("Name: Krrish Kohli\n");
    printf("Algorithm: merge sort, Language: C");
    printf("\n\n");

    // Test 1: Empty array
    int t1[] = {};
    int n1 = 0;
    printf("Input:  ");
    print_array(t1, n1);
    merge_sort(t1, n1);
    printf("\nSorted: ");
    print_array(t1, n1);
    printf("\n\n");

    // Test 2: Single element
    int t2[] = {3};
    int n2 = 1;
    printf("Input:  ");
    print_array(t2, n2);
    merge_sort(t2, n2);
    printf("\nSorted: ");
    print_array(t2, n2);
    printf("\n\n");

    // Test 3: Small array
    int t3[] = {3, 2, 1};
    int n3 = 3;
    printf("Input:  ");
    print_array(t3, n3);
    merge_sort(t3, n3);
    printf("\nSorted: ");
    print_array(t3, n3);
    printf("\n\n");

    // Test 4: Larger array with negatives
    int t4[] = {42, -33, 102, -74, 30, 1, 1000, -756, 33, -7, 10};
    int n4 = sizeof(t4) / sizeof(t4[0]);
    printf("Input:  ");
    print_array(t4, n4);
    merge_sort(t4, n4);
    printf("\nSorted: ");
    print_array(t4, n4);
    printf("\n");

    return 0;
}
