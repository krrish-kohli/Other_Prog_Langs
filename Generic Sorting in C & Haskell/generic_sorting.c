/* CECS 342 – Assignment 5
   Name: Krrish Kohli
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[32];
    int age;
} Person;

//Using this function for qsort.
static int double_asc(const void *a, const void *b)
{
    double da = *(const double*)a; 
    double db = *(const double*)b;
    return (da > db) - (da < db);
}

// sort persons by alphabetical order of their names.
static int person_name_asc(const void *a, const void *b)
{
    const Person *pa = (const Person*)a;
    const Person *pb = (const Person*)b;
    return strcmp(pa->name, pb->name);
}

// sort persons by descending order of their ages if tie sort by ascending order of their name.
static int person_age_desc_name_asc(const void *a, const void *b)
{
    //(const Person*)a/b is cast the untyped pointer a to a pointer to const Person
    const Person *pa = (const Person*)a;
    const Person *pb = (const Person*)b;

    if(pa->age != pb->age)
        return (pb->age - pa->age);
    return strcmp(pa->name, pb->name);
}

//Print array of the numbers
static void print_numbers(const double *xs, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%s%.2f", (i ? ", " : ""), xs[i]);
    }
    printf("\n");
}


//Print array of people
static void print_people(const Person *ps, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%s%s, %d", (i ? "; " : ""), ps[i].name, ps[i].age);
    }
    printf("\n");
}
