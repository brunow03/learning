Console.WriteLine("***** Fun with type Conversions *****");

// Add two shorts and print the result.
short numb1 = 9, numb2 = 10;
Console.WriteLine("{0} + {1} = {2}", numb1, numb2, Add(numb1, numb2));
Console.ReadLine();

static int Add(int x, int y) {
    return x + y;
}