/* CECS 342 – Assignment 5
 * main.c
 * Name: Krrish Kohli
 * Tools used:
 * - Compiler: gcc
 * - Editor: VS Code
 * - Terminal / Shell: Mac Terminal / bash
 * - Websites: haskell.org, gemini.com, chatgpt.com, https://en.wikipedia.org/wiki/Generic_programming, https://www.geeksforgeeks.org/c/qsort-function-in-c/
*/


#include "generic_sorting.c"

//data of the sequence of double numbers.
double numbers[] = {645.41,    37.59,   76.41,    5.31, 
                    -34.23,     1.11,    1.10,   23.46, 
                    635.47,  -876.32,  467.83,   62.25};
const size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]);


//data of the sequence of people (name and age)
Person people[] = {{"Hal", 20},      {"Susann", 31},   {"Dwight", 19}, 
                   {"Kassandra", 21},{"Lawrence", 25}, {"Cindy", 22}, 
                   {"Cory", 27},     {"Mac", 19},      {"Romana", 27}, 
                   {"Doretha", 32},  {"Danna", 20},    {"Zara", 23},
                   {"Rosalyn", 26},  {"Risa", 24},     {"Benny", 28}, 
                   {"Juan", 33},     {"Natalie", 25}};
const size_t people_len = sizeof(people) / sizeof(people[0]);

int main(void)
{
    printf("CECS 342 Assignment 5\n");
    printf("Name: Krrish Kohli\n");
    printf("Generic Sort by qsort, Language: C\n\n");

    printf("Task a):\n");
    printf("Unsorted Numbers:\n");
    print_numbers(numbers, numbers_len);
    qsort(numbers, numbers_len, sizeof(double), double_asc);
    printf("Sorted Numbers:\n");
    print_numbers(numbers, numbers_len);
    printf("\n");

    printf("Task b):\n");
    printf("Unsorted name and age:\n");
    print_people(people, people_len);
    qsort(people,people_len, sizeof(Person), person_name_asc);
    printf("Sorted name ascending order:\n");
    print_people(people, people_len);
    printf("\n");

    //Updated Person like the initial data to do other sort.
    Person people_sorted_by_age [sizeof(people) / sizeof(people[0])];
    memcpy(people_sorted_by_age, people, sizeof(people));

    printf("Task c):\n");
    qsort(people_sorted_by_age,people_len, sizeof(Person), person_age_desc_name_asc);
    printf("Sorted age descending order and name ascending (if age equal):\n");
    print_people(people_sorted_by_age, people_len);
    printf("\n");
    return 0;
}
