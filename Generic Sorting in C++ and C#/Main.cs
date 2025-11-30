/* CECS 342 – Assignment 6
 * Main.cs
 * Name: Krrish Kohli
 * Tools used:
 * - Compiler: gcc
 * - Editor: VS Code
 * - Terminal / Shell: Mac Terminal / bash
 * - Websites: haskell.org, gemini.com, chatgpt.com, https://en.wikipedia.org/wiki/Generic_programming, https://www.geeksforgeeks.org/cpp/c-qsort-vs-c-sort/, https://learn.microsoft.com/en-us/dotnet/csharp/programming-guide/
*/

using System;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("CECS 342 Assignment 5");
        Console.WriteLine("Name: Krrish Kohli");
        Console.WriteLine("Generic Sort by Array.Sort, Language: C#");
        Console.WriteLine();

        // ---- Data: same numbers as in the C assignment ----
        double[] numbers =
        {
            645.41,  37.59,  76.41,   5.31,
            -34.23,   1.11,   1.10,  23.46,
            635.47, -876.32, 467.83, 62.25
        };

        // ---- Data: same people (name, age) ----
        Person[] people =
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

        // Copies of people so we can sort differently without losing original
        Person[] peopleByName = new Person[people.Length];
        Person[] peopleByAge  = new Person[people.Length];
        Array.Copy(people, peopleByName, people.Length);
        Array.Copy(people, peopleByAge,  people.Length);

        // -------- Task a): sort numbers ascending --------
        Console.WriteLine("Task a):");
        Console.WriteLine("Unsorted Numbers:");
        GenericSorting.PrintNumbers(numbers);

        Array.Sort(numbers, GenericSorting.DoubleAsc);

        Console.WriteLine("Sorted Numbers:");
        GenericSorting.PrintNumbers(numbers);
        Console.WriteLine();

        // -------- Task b): sort people alphabetically by name --------
        Console.WriteLine("Task b):");
        Console.WriteLine("Unsorted name and age:");
        GenericSorting.PrintPeople(people);

        Array.Sort(peopleByName, GenericSorting.PersonNameAsc);

        Console.WriteLine("Sorted name ascending order:");
        GenericSorting.PrintPeople(peopleByName);
        Console.WriteLine();

        // -------- Task c): sort people by age desc, then name asc --------
        Console.WriteLine("Task c):");

        Array.Sort(peopleByAge, GenericSorting.PersonAgeDescNameAsc);

        Console.WriteLine("Sorted age descending order and name ascending (if age equal):");
        GenericSorting.PrintPeople(peopleByAge);
        Console.WriteLine();
    }
}
