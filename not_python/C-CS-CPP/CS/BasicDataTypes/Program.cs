using System.Numerics;
using System.Runtime.CompilerServices;
using System.Text;

Console.WriteLine("***** Fun with Basic Data Types *****");

LocalVarDeclarations();
DefaultDeclarations();
ObjectFunctionality();
DataTypeFunctionality();
BooleanFunctionality();
CharFunctionality();
ParseFromStrings();
ParseFromStringsWithTryParse();
UseDatesAndTimes();
UseBigInteger();
DigitSeparators();
BinaryLiterals();

Console.WriteLine("***** Now Fun with Basic Strings Functionalities *****");
Console.WriteLine();

BasicStringFunctionality();
StringConcatenation();
EscapeChars();
StringInterpolation();
StringInterpolationWithDefaultInterpolatedStringHandler();
StringEqualitySpecifyingCompareRules();
StringsAreImmutable();

static void StringsAreImmutable()
{
	Console.WriteLine("=> Immutable Strings:\a");
	// Set initial string value.
	string s1 = "This is my string.";
	Console.WriteLine("s1 = {0}", s1);
	// Uppercase s1?
	string upperString = s1.ToUpper();
	Console.WriteLine("upperString = {0}", upperString);
	// Nope! s1 is in the same format!
	Console.WriteLine("s1 = {0}", s1);
	Console.WriteLine();
}

static void StringEqualitySpecifyingCompareRules()
{
	Console.WriteLine("=> String equality (Case Insensitive:");
	string s1 = "Hello!";
	string s2 = "HELLO!";
	Console.WriteLine("s1 = {0}", s1);
	Console.WriteLine("s2 = {0}", s2);
	Console.WriteLine();
	
	// Check the results of changing the default compare rules.
	Console.WriteLine("Default rules: s1={0},s2={1}s1.Equals(s2): {2}", s1, s2, s1.Equals(s2));
	Console.WriteLine("Ignore case: s1.Equals(s2, StringComparison.OrdinalIgnoreCase): {0}", s1.Equals(s2, StringComparison.OrdinalIgnoreCase));
	
	Console.WriteLine("Ignore case, Invariant Culture: s1.Equals(s2, StringComparison. InvariantCultureIgnoreCase): {0}", s1.Equals(s2, StringComparison.InvariantCultureIgnoreCase));
	Console.WriteLine();
	
	Console.WriteLine("Default rules: s1={0},s2={1} s1.IndexOf(\"E\"): {2}", s1, s2, s1.IndexOf("E"));
	Console.WriteLine("Ignore case: s1.IndexOf(\"E\", StringComparison.OrdinalIgnoreCase): {0}", s1.IndexOf("E", StringComparison.OrdinalIgnoreCase));
	Console.WriteLine("Ignore case, Invariant Culture: s1.IndexOf(\"E\", StringComparison. InvariantCultureIgnoreCase): {0}", s1.IndexOf("E", StringComparison.InvariantCultureIgnoreCase));
	Console.WriteLine();
}

static void StringInterpolationWithDefaultInterpolatedStringHandler()
{
	Console.WriteLine("=> String interpolation under the covers:\a");
	int age = 4;
	string name = "Soren";
	var builder = new DefaultInterpolatedStringHandler(3,2);
	builder.AppendLiteral("\tHello ");
	builder.AppendFormatted(name);
	builder.AppendLiteral(" you are ");
	builder.AppendFormatted(age);
	builder.AppendLiteral(" years old.");
	var greeting = builder.ToStringAndClear();
	Console.WriteLine(greeting);
	Console.WriteLine();
}

static void StringInterpolation()
{
	Console.WriteLine("=> String interpolation:\a");
	
	// Some local variables we will plug into our larger string
	int age = 4;
	string name = "Soren";
	
	// Using curly-bracket syntax.
	string greeting = string.Format("Hello {0} you are {1} years old.", name, age);
	Console.WriteLine(greeting);
	
	// Using string interpolation
	string greeting2 = $"Hello {name} you are {age} years old.";
	Console.WriteLine(greeting2);
	Console.WriteLine();
}

static void EscapeChars()
{
	Console.WriteLine("=> Escape characters:");
	string strWithTabs = "Model\tColor\tSpeed\tPet Name ";
	Console.WriteLine(strWithTabs);
	
	Console.WriteLine("Everyone loves \"Hello World\" ");
	Console.WriteLine("C:\\MyApp\\bin\\Debug ");
	
	// Adds a total of 4 blank lines (3 escaped, 1 from WriteLine).
	Console.WriteLine("All finished.\n\n\n ");
	Console.WriteLine();

	//omitted for brevity
	// Adds a 4 more blank lines.
	Console.WriteLine("All finished for real this time.{0}{0}{0}",Environment.NewLine);
}

static void StringConcatenation()
{
	Console.WriteLine("=> String concatenation:");
	string s1 = "Programming the ";
	string s2 = "PsychoDrill (PTP)";
	string s3 = s1 + s2;
	Console.WriteLine(s3);
	Console.WriteLine();
}

static void BasicStringFunctionality()
{
	Console.WriteLine("=> Basic String functionality:"); 
	string firstName = "Freddy";
	Console.WriteLine("Value of firstName: {0}", firstName);
	Console.WriteLine("firstName has {0} characters.", firstName.Length);
	Console.WriteLine("firstName in uppercase: {0}", firstName.ToUpper());
	Console.WriteLine("firstName in lowercase: {0}", firstName.ToLower());
	Console.WriteLine("firstName contains the letter y?: {0}", firstName.Contains("y"));
	Console.WriteLine("New first name: {0}", firstName.Replace("dy", ""));
	Console.WriteLine();
}

static void BinaryLiterals()
{	
	//Updated in 7.2, Binary can begin with _
	Console.WriteLine("=> Use Binary Literals:");
	Console.WriteLine("Sixteen: {0}",0b_0001_0000);
	Console.WriteLine("Thirty Two: {0}",0b_0010_0000);
	Console.WriteLine("Sixty Four: {0}",0b_0100_0000);
	Console.WriteLine();
}

static void DigitSeparators()
{
	Console.WriteLine("=> Use Digit Separators:");
	
	Console.Write("Integer:");
	Console.WriteLine(123_456);
	
	Console.Write("Long:");
	Console.WriteLine(123_456_789L);
	
	Console.Write("Float:");
	Console.WriteLine(123_456.1234F);
	
	Console.Write("Double:");
	Console.WriteLine(123_456.12);
	
	Console.Write("Decimal:");
	Console.WriteLine(123_456.12M);
	
	//Updated in 7.2, Hex can begin with _
	Console.Write("Hex:");
	Console.WriteLine(0x_00_00_FF);
	Console.WriteLine();
}

static void UseBigInteger()
{
	Console.WriteLine("=> Use BigInteger:");
	BigInteger biggy = BigInteger.Parse("9999999999999999999999999999999999999999999999");
	Console.WriteLine("Value of biggy is {0}", biggy);
	Console.WriteLine("Is biggy an even value?: {0}", biggy.IsEven);
	Console.WriteLine("Is biggy a power of two?: {0}", biggy.IsPowerOfTwo);
	BigInteger reallyBig = BigInteger.Multiply(biggy, BigInteger.Parse("8888888888888888888888888888888888888888888"));
	Console.WriteLine("Value of reallyBig is {0}", reallyBig);
	BigInteger reallyBig2 = reallyBig + biggy;
	Console.WriteLine("reallyBig plus biggy: {0}", reallyBig2);
	Console.WriteLine();
}

static void LocalVarDeclarations()
{
	Console.WriteLine("=> Data Declarations:");
	// Local variables are declared and initialized as follows:
	// dataType varName = initialValue;
	int myInt = 0;
	string myString;
	myString = "This is my character data";
	// Declare 3 bools on a single line.
	bool b1 = true, b2 = false, b3 = b1;
	// Use System.Boolean data type to declare a bool.
	System.Boolean b4 = false;
	Console.WriteLine("Your data: {0}, {1}, {2}, {3}, {4}, {5}",
	myInt, myString, b1, b2, b3, b4);
	Console.WriteLine();
}

static void DefaultDeclarations() {
	Console.WriteLine("=> Default Declarations:");
	int myInt = default;
	Console.WriteLine(myInt);
	Console.WriteLine();
}

static void ObjectFunctionality()
{
	Console.WriteLine("=> System.Object Functionality:");
	// A C# int is really a shorthand for System.Int32,
	// which inherits the following members from System.Object.
	Console.WriteLine("12.GetHashCode() = {0}", 12.GetHashCode());
	Console.WriteLine("12.Equals(23) = {0}", 12.Equals(23));
	Console.WriteLine("12.ToString() = {0}", 12.ToString());
	Console.WriteLine("12.GetType() = {0}", 12.GetType());
	Console.WriteLine();
}

static void DataTypeFunctionality()
{
	Console.WriteLine("=> Data type Functionality:");
	Console.WriteLine("Max of int: {0}", int.MaxValue);
	Console.WriteLine("Min of int: {0}", int.MinValue);
	Console.WriteLine("Max of double: {0}", double.MaxValue);
	Console.WriteLine("Min of double: {0}", double.MinValue);
	Console.WriteLine("double.Epsilon: {0}", double.Epsilon);
	Console.WriteLine("double.PositiveInfinity: {0}",
	double.PositiveInfinity);
	Console.WriteLine("double.NegativeInfinity: {0}",
	double.NegativeInfinity);
	Console.WriteLine();
}

static void BooleanFunctionality() {
	Console.WriteLine("bool.FalseString: {0}", bool.FalseString);
	Console.WriteLine("bool.TrueString: {0}", bool.TrueString);
	Console.WriteLine();
}

static void CharFunctionality()
{
	Console.WriteLine("=> char type Functionality:");
	char myChar = 'a';
	Console.WriteLine("char.IsDigit('a'): {0}", char.IsDigit(myChar));
	Console.WriteLine("char.IsLetter('a'): {0}", char.IsLetter(myChar));
	Console.WriteLine("char.IsWhiteSpace('Hello There', 5): {0}",
	char.IsWhiteSpace("Hello There", 5));
	Console.WriteLine("char.IsWhiteSpace('Hello There', 6): {0}",
	char.IsWhiteSpace("Hello There", 6));
	Console.WriteLine("char.IsPunctuation('?'): {0}",
	char.IsPunctuation('?'));
	Console.WriteLine();
}

static void ParseFromStrings()
{
	Console.WriteLine("=> Data type parsing:");
	bool b = bool.Parse("True");
	Console.WriteLine("Value of b: {0}", b);
	double d = double.Parse("99.884");
	Console.WriteLine("Value of d: {0}", d);
	int i = int.Parse("8");
	Console.WriteLine("Value of i: {0}", i);
	char c = Char.Parse("w");
	Console.WriteLine("Value of c: {0}", c);
	Console.WriteLine();
}

static void ParseFromStringsWithTryParse()
{
	Console.WriteLine("=> Data type parsing with TryParse:");
	
	if (bool.TryParse("True", out bool b)) {
		Console.WriteLine("Value of b: {0}", b);
	}
	else {
		Console.WriteLine("Default value of b: {0}", b);
	}
	
	string value = "Hello";
	if (double.TryParse(value, out double d)) {
		Console.WriteLine("Value of d: {0}", d);
	}
	else {
		Console.WriteLine("Failed to convert the input ({0}) to a double and the variable was assigned the default {1}", value,d);
	}
	
	Console.WriteLine();
}

static void UseDatesAndTimes()
{
	Console.WriteLine("=> Dates and Times:");
	
	// This constructor takes (year, month, day).
	DateTime dt = new DateTime(2015, 10, 17);
	
	// What day of the month is this?
	Console.WriteLine("The day of {0} is {1}", dt.Date, dt.DayOfWeek);
	
	// Month is now December.
	dt = dt.AddMonths(2);
	Console.WriteLine("Daylight savings: {0}", dt.IsDaylightSavingTime());
	
	// This constructor takes (hours, minutes, seconds).
	TimeSpan ts = new TimeSpan(4, 30, 0);
	Console.WriteLine(ts);
	
	// Subtract 15 minutes from the current TimeSpan and
	// print the result.
	Console.WriteLine(ts.Subtract(new TimeSpan(0, 15, 0)));
	
	Console.WriteLine();
}