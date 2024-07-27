Console.WriteLine("***** My First C# App *****");
Console.WriteLine("Hello, World!");
Console.WriteLine();

foreach (string arg in args) 
{
	Console.WriteLine("Arg: {0}", arg);
}

for (int i = 0; i < args.Length; i++) {
	Console.WriteLine("Arg: {0}", args[i]);
}

string[] theArgs = Environment.GetCommandLineArgs();

foreach (string arg in theArgs) 
{
	Console.WriteLine("Arg: {0}", arg);
}

ShowEnvironmentDetails();

Console.ReadLine();
return 0;

static void ShowEnvironmentDetails() {
	foreach (string drive in Environment.GetLogicalDrives()) {
		Console.WriteLine("Drive: {0}", drive);
	}
	Console.WriteLine("OS: {0}", Environment.OSVersion);
	Console.WriteLine("Number of processors: {0}", Environment.ProcessorCount);
	Console.WriteLine(".NET Core Version: {0}", Environment.Version);
}