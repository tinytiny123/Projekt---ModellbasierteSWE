using System;

class Program
{
    static void Main()
    {
        int x = 12; y = 2; z = 3;
        var result = ExampleM(x, y, z);
        Console.WriteLine(result.HasValue ? result.ToString() : "Nothing");
    }

    static int? DivSafe(int n, int m)
    {
        if (m == 0) return null;
        return n / m;
    }

    static int? ExampleM(int x, int y, int z)
    {
        return DivSafe(x, y)
            .SelectMany(res => DivSafe(res, z));
    }
}
