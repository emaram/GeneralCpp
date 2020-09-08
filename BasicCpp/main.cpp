#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void lastDigitSquare();
void getInverseNumber();
void getSumProdDivisors();
void getBestUnit();

// ----------------------------------------
// main(): Everything starts here :-)
// ----------------------------------------
int main(int argc, char* argv[])
{
	int op;

	while (true) {
		system("clear");
		cout << endl << endl;
		cout << "*****************************************" << endl;
		cout << "Basic C++ functions" << endl;
		cout << "*****************************************" << endl;
		cout << "1. Get square of last digit" << endl;
		cout << "2. Get inverse number for digits avg < 5" << endl;
		cout << "3. Get sum and prod for divisors of a number" << endl;
		cout << "4. Get most profitable unit" << endl;
		cout << "0. EXIT" << endl;
		cout << "*****************************************" << endl;
		cout << "Your option: ";
		cin >> op;

		cout << endl << endl << endl;

		switch (op)
		{
		case 1:
			lastDigitSquare();
			break;
		case 2:
			getInverseNumber();
			break;
		case 3:
			getSumProdDivisors();
			break;
		case 4:
			getBestUnit();
			break;
		case 0:
			system("clear");
			return 0;
		default:
			break;
		}

	}

	return 0;
}

// ----------------------------------------
// Reads an integer n and displays all numbers
// from 0 to 1000 that have last digit == n
// ----------------------------------------
void lastDigitSquare()
{
	unsigned int n;
	cout << "Input n (0..9): ";
	cin >> n;

	if (n >= 10) {
		cout << "Error: n must be a digit" << endl;
		return;
	}

	bool found = false;
	for (int i = 0; i <= 1000; i++) {
		if ( (i*i) % 10 == n ) {
			cout << i << " ";
			found = true;
		} 
	}

	if (found == false)
		cout << "There is no number with last digit == " << n;

	cout << endl << endl;
	system( "read -n 1 -s -p \"Press any key to continue...\"" );
}

// ----------------------------------------
// Reads positive integers (stops when 0).
// For each number, gets all digits and calculates average.
// If avg < 5, prints the inverse of that number (e.g. if number is 1034, print 4301)
// ----------------------------------------
void getInverseNumber()
{
	unsigned int number = 1;
	unsigned int sumdigits = 0;
	unsigned int inverse = 0;

	while (number > 0) {
		cout << "Input n: ";
		cin >> number;

		inverse = 0;
		sumdigits = 0;
		unsigned int x = 0;
		unsigned int temp = number;
		while (temp > 0) {
			int digit = temp % 10;
			inverse = inverse * 10 + digit;
			sumdigits += digit;
			temp /= 10;
			x++;
		}

		if (x > 0) {
			if (sumdigits / x < 5)
				cout << "Inverse number is: " << inverse << endl;
			else
				cout << "The average of its digits is >= 5" << endl;
		}

	}
	cout << endl << endl;
	system( "read -n 1 -s -p \"Press any key to continue...\"" );

}

// ----------------------------------------
// Reads an integer number and obtains its divisor.
// Prints the sum and prod of its divisors.
// If no divisor, prints a message.
// ----------------------------------------
void getSumProdDivisors()
{
	unsigned int n;
	cout << "Input n: ";
	cin >> n;

	unsigned int sum = 0;
	unsigned int prod = 1;

	for (unsigned int i = 2; i <= n/2; i++) {
		if (n % i == 0) {
			sum += i;
			prod *= i;
		}
	}
	if (sum == 0)
		cout << "There is no divisor for " << n << endl;
	else
	{
		cout << "Sum of its divisors is: " << sum << endl;
		cout << "Prod of its divisors is: " << prod << endl;
	}
	cout << endl << endl;
	system( "read -n 1 -s -p \"Press any key to continue...\"" );

}

// ----------------------------------------
// A company has a number n of units. (1 < n < 5)
// Each unit reported its profit for Q1, Q2, Q3, Q4.
// This function displays the best profitable unit for quarter q.
// ----------------------------------------
void getBestUnit()
{
	int n, q;
	cout << "Input number of units (1..5): ";
	cin >> n;
	cout << endl;

	int q1[5], q2[5], q3[5], q4[5];
	cout << "Input quarterly profits: " << endl;
	cout << "        Q1 Q2 Q3 Q4" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Unit " << i+1 << ": ";
		cin >> q1[i] >> q2[i] >> q3[i] >> q4[i];
	}

	cout << endl << "Input quarter (1..4): ";
	cin >> q;
	int max = 0;
	switch (q)
	{
	case 1:
		for (int i = 0; i < n; i++) {
			if (max < q1[i])
				max = q1[i];
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			if (max < q2[i])
				max = q2[i];
		}
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			if (max < q3[i])
				max = q3[i];
		}
		break;
	case 4:
		for (int i = 0; i < n; i++) {
			if (max < q4[i])
				max = q4[i];
		}
		break;
	
	default:
		break;
	}

	cout << "The most profitable unit on quarter " << q << " is " << max << endl;

	cout << endl << endl;
	system( "read -n 1 -s -p \"Press any key to continue...\"" );

}