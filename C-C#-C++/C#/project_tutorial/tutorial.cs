using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace project_tutorial
{
	class tutorial 
	{
		static void Main(string[] args)
		{
			Console.Write("Enter your name: ");
			string name = Console.ReadLine();
			Console.WriteLine("Hello, " + name);

			Console.ReadLine();
			/*
			Console.WriteLine("Hello World!");
			Console.ReadLine();
			Console.WriteLine("   /|");
			Console.WriteLine("  / |");
			Console.WriteLine(" /  |");
			Console.WriteLine("/___|");
			Console.ReadLine();
			*/
		}

		static void SayHi()
		{
			Console.WriteLine("Hello User");
		}
	}
}