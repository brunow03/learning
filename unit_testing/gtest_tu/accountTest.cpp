#include <iostream>
#include <gtest/gtest.h>
#include "account.cpp"

using namespace std;

TEST(BankAccount, test1)
{
	BankAccount instance;
	instance.deposite(100);
	EXPECT_EQ(100, instance.balance);

}

int main(int argc, char const *argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}


