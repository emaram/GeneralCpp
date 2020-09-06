#include <iostream>

using namespace std;

void lastDigitSquare();

// ----------------------------------------
// main(): Everything starts here :-)
// ----------------------------------------
int main(int argc, char* argv[])
{
	lastDigitSquare();
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

	cout << endl;
}