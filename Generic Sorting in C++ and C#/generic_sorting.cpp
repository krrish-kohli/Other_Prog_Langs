/* CECS 342 – Assignment 6
   Name: Krrish Kohli
*/

#include <stdio.h>   // for printf
#include <stdlib.h>  // for qsort
#include <string.h>  // for strcmp

// This struct represents one person: a name + an age.
typedef struct {
    char name[32];
    int age;
} Person;

// Using this function for qsort.
static int double_asc(const void *a, const void *b)
{
    // Cast the void* pointers to double*
    double da = *(const double*)a;
    double db = *(const double*)b;

    // (da > db) is 1 or 0, (da < db) is 1 or 0
    // So result is 1, 0, or -1
    return (da > db) - (da < db);
}

// Sort persons by alphabetical order of their names.
static int person_name_asc(const void *a, const void *b)
{
    // Cast the void* to Person*
    const Person *pa = (const Person*)a;
    const Person *pb = (const Person*)b;

    // strcmp returns <0, 0, or >0 depending on alphabetical order
    return strcmp(pa->name, pb->name);
}

// Sort persons by descending order of their ages, if tie then sort by ascending order of their names.
static int person_age_desc_name_asc(const void *a, const void *b)
{
    // Cast the void* to Person*
    const Person *pa = (const Person*)a;
    const Person *pb = (const Person*)b;

    // First compare ages (we want larger age first)
    if (pa->age != pb->age) {
        // pb->age - pa->age > 0 means pb is older, so pb comes first
        return (pb->age - pa->age);  // descending by age
    }

    // If ages are equal, compare names A to Z
    return strcmp(pa->name, pb->name);
}

// Print an array of numbers
static void print_numbers(const double *xs, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        // Print commas between numbers, and 2 decimal places
        printf("%s%.2f", (i ? ", " : ""), xs[i]);
    }
    printf("\n");
}

// Print an array of people
static void print_people(const Person *ps, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        // Print semicolons between entries
        printf("%s%s, %d", (i ? "; " : ""), ps[i].name, ps[i].age);
    }
    printf("\n");
}
