/* CECS 342 – Assignment 6
   Name: Krrish Kohli
*/

using System;
using System.Collections.Generic;
using System.Linq;

public class Person
{
    public string Name{get; set;}
    public int Age{get; set;}

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
}

public static class GenericSorting
{
    // Compare two doubles for ascending order
    public static IEnumerable<double> SortNumbersAsc(IEnumerable<double> numbers)
    {
        return numbers.OrderBy(x => x);
    }

    // Compare two Person by name
    public static IEnumerable<Person> PersonNameAsc(IEnumerable<Person> people)
    {
        return people.OrderBy(p => p.Name);
    }

    // Compare two Person by:
    // 1) age in descending order,
    // 2) if ages are equal, then by name ascending
    public static IEnumerable<Person> PersonAgeDescNameAsc(IEnumerable<Person> people)
    {
        return people.OrderByDescending(p => p.Age).ThenBy(p => p.Name);
    }

    // Print array of the numbers
    public static string PrintNumbers(IEnumerable<double> numbers)
    {
        return string.Join(", ", numbers.Select(x => x.ToString("F2")));
    }

    // Print array of the people
    public static string FormatPeople(IEnumerable<Person> people)
    {
        return string.Join("; ", people.Select(p => $"{p.Name}, {p.Age}"));
    }
}
