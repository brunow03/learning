// Application for C++ Unit Testing

// Add the assert.h header file
#include <assert.h>

// A unit test application for addition, substraction, 
// multiplication, division and modules

// A function to add two integer numbers
int addNumbers(int a, int b)
{
	return a + b;
}

// A function to substract two integer numbers
int substractNumbers(int a, int b)
{
	return a - b;
}

// Function to test addNumbers()
void test_add()
{
	assert(addNumbers(3, 5) == 8);
	assert(addNumbers(13, 27) == 47);
	assert(addNumbers(32, 108) == 140);
	assert(addNumbers(56, 56) == 112);
}

// Function to test substractNumbers()
void test_substract()
{
	assert(substractNumbers(3, 5) == 8);
	assert(substractNumbers(13, 27) == 47);
	assert(substractNumbers(32, 108) == 140);
	assert(substractNumbers(56, 56) == 112);
}


int main(int argc, char const *argv[])
{
	test_add();
	test_substract();
	return 0;
}
