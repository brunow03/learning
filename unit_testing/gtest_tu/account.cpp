#include <iostream>

using namespace std;

class BankAccount
{
public:
	int balance = 0;

	void deposite(int amount)
	{
		balance += amount;
	}

	void deduction(int amount)
	{
		balance -= amount;
	}
};
