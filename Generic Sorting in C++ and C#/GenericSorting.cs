/* CECS 342 – Assignment 6
   Name: Krrish Kohli
*/

using System;

class Person
{
    public string Name;
    public int Age;

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public override string ToString()
    {
        return Name + ", " + Age;
    }
}

static class GenericSorting
{
    // Compare two doubles for ascending order
    public static int DoubleAsc(double a, double b)
    {
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }

    // Compare two Person by name (alphabetical A–Z)
    public static int PersonNameAsc(Person a, Person b)
    {
        return string.Compare(a.Name, b.Name, StringComparison.Ordinal);
    }

    // Compare two Person by:
    //  1) age in descending order (larger age first),
    //  2) if ages are equal, by name ascending (A–Z)
    public static int PersonAgeDescNameAsc(Person a, Person b)
    {
        if (a.Age != b.Age)
        {
            // For descending age: higher age should come first
            return b.Age - a.Age;  // positive if b older, negative if a older
        }

        // If ages are equal, compare names A–Z
        return string.Compare(a.Name, b.Name, StringComparison.Ordinal);
    }

    // Print array of numbers like in your C code
    public static void PrintNumbers(double[] xs)
    {
        for (int i = 0; i < xs.Length; i++)
        {
            string prefix = (i > 0) ? ", " : "";
            Console.Write(prefix + xs[i].ToString("F2"));
        }
        Console.WriteLine();
    }

    // Print array of people like in your C code
    public static void PrintPeople(Person[] ps)
    {
        for (int i = 0; i < ps.Length; i++)
        {
            string prefix = (i > 0) ? "; " : "";
            Console.Write(prefix + ps[i].Name + ", " + ps[i].Age);
        }
        Console.WriteLine();
    }
}
