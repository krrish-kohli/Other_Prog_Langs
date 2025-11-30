/* CECS 342 – Assignment 6
 * Main.cs
 * Name: Krrish Kohli
 * Tools used:
 * - Compiler: gcc
 * - Editor: VS Code
 * - Terminal / Shell: Mac Terminal / bash
 * - Websites: haskell.org, gemini.com, chatgpt.com, https://en.wikipedia.org/wiki/Generic_programming, https://www.geeksforgeeks.org/cpp/c-qsort-vs-c-sort/, https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/, https://learn.microsoft.com/en-us/dotnet/csharp/linq/, https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic?view=net-10.0
*/

using System;
using System.Collections.Generic;

class MainProg
{
    static void Main(string[] args)
    {
        Console.WriteLine("CECS 342 Assignment 6");
        Console.WriteLine("Name: Krrish Kohli");
        Console.WriteLine("Generic Sort, Language: C#");
        Console.WriteLine();

        double[] numbers =
        {
            645.41,  37.59,  76.41,   5.31,
            -34.23,   1.11,   1.10,  23.46,
            635.47, -876.32, 467.83, 62.25
        };

        var people = new List<Person>
        {
            new Person("Hal", 20),
            new Person("Susann", 31),
            new Person("Dwight", 19),
            new Person("Kassandra", 21),
            new Person("Lawrence", 25),
            new Person("Cindy", 22),
            new Person("Cory", 27),
            new Person("Mac", 19),
            new Person("Romana", 27),
            new Person("Doretha", 32),
            new Person("Danna", 20),
            new Person("Zara", 23),
            new Person("Rosalyn", 26),
            new Person("Risa", 24),
            new Person("Benny", 28),
            new Person("Juan", 33),
            new Person("Natalie", 25)
        };

        // -------- Task a): sort numbers ascending --------
        Console.WriteLine("Task a):");
        Console.WriteLine("Unsorted Numbers:");
        Console.WriteLine(GenericSorting.PrintNumbers(numbers));

        var numbersSorted = GenericSorting.SortNumbersAsc(numbers);

        Console.WriteLine("Sorted Numbers:");
        Console.WriteLine(GenericSorting.PrintNumbers(numbersSorted));
        Console.WriteLine();

        // -------- Task b): sort people alphabetically by name --------
        Console.WriteLine("Task b):");
        Console.WriteLine("Unsorted name and age:");
        Console.WriteLine(GenericSorting.FormatPeople(people));

        var peopleSortedbyName = GenericSorting.PersonNameAsc(people);

        Console.WriteLine("Sorted name ascending order:");
        Console.WriteLine(GenericSorting.FormatPeople(peopleSortedbyName));
        Console.WriteLine();

        // -------- Task c): sort people by age desc, then name asc --------
        Console.WriteLine("Task c):");

        var PeopleSortedbyAgethenName = GenericSorting.PersonAgeDescNameAsc(people);

        Console.WriteLine("Sorted age descending order and name ascending (if age equal):");
        Console.WriteLine(GenericSorting.FormatPeople(PeopleSortedbyAgethenName));
        Console.WriteLine();
    }
}
