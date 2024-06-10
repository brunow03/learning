#include <iostream>
	
void simple();

using namespace std;
int main(int argc, char const *argv[])
{
	cout << "main() will call the simple() function:\n";
	simple();
	cout << "main() is finished with the simple() function.\n";
	return 0;
}

void simple()
{
	cout << "I'm but a simple function.\n";
}