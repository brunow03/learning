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
			try 
			{
				int num1 = Convert.ToInt32(Console.ReadLine());
				int num2 = Convert.ToInt32(Console.ReadLine());

				Console.WriteLine(num1 / num2);
			} 
			catch (DividedByZeroException e) 
			{
				Console.WriteLine(e.Message);
			} 
			catch (FormatException e) 
			{
				Console.WriteLine(e.Message);
			}
			finally // optional
			{

			}

			

			Console.ReadLine();
		}
	}
}