#include <iostream>
#include <cstdlib>

using namespace std;

class BankAccount
{
	float bal;

	void secureUpdate(float x, char op)
	{
		if (op == '+')
		{
			bal += x;
		}
		else if (op == '-')
		{
			if (x < bal)
			{
				bal -= x;
			}
			else
			{
				cout << "Amount too large!" << endl;
			}
		}
		else
		{
			cout << "Incorrect use." << endl;
		}
	}

public:
	void setBalance(float x);
	void showBalance(void);
	void Deposit(float x);
	void Withdraw(float x);
};

void BankAccount ::setBalance(float x)
{
	bal = x;
}

void BankAccount ::showBalance(void)
{
	cout << "Current Balance: " << bal << endl;
}

void BankAccount ::Deposit(float x)
{
	secureUpdate(x, '+');
}

void BankAccount ::Withdraw(float x)
{
	secureUpdate(x, '-');
}

int main()
{
	BankAccount myAccount;
	cout << "Options:\n\t1) Set Balance\n\t2) Show Balance\n\t3) Deposit\n\t4) Withdraw\n\t5) Exit\n\n";
	while (1)
	{
		int in;
		float t;
		cout << "Enter option: ";
		cin >> in;
		switch (in)
		{
		case 1:
			cout << "Enter new balance: ";
			cin >> t;
			myAccount.setBalance(t);
			break;

		case 2:
			myAccount.showBalance();
			break;
		case 3:
			cout << "Enter amount: ";
			cin >> t;
			myAccount.Deposit(t);
			break;
		case 4:
			cout << "Enter amount: ";
			cin >> t;
			myAccount.Withdraw(t);
			break;
		case 5:
			cout << "Exiting...\n";
			exit(0);
		default:
			"Invalid Input!\n";
		}
	}

	return 0;
}
