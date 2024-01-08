using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var myList = new List<int> { 2 };

        var resList = myList.SelectMany(SquareAndCube)
                            .SelectMany(SquareAndCube)
                            .ToList();

        foreach (var item in resList)
        {
            Console.Write(item + " ");
        }
    }

    static IEnumerable<int> SquareAndCube(int n)
    {
        return new List<int> { n, n * n, n * n * n };
    }
}