#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// To convert Decimal Number to Binary Number
void DecimalToBinary (float);

int main ()
{
	float decimal;
	char x;
	
	do
	{
		cout << "Enter Decimal number: ";
	    cin >> decimal;
		DecimalToBinary(decimal);
		cout << "Try Again (y/n)? ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

void  DecimalToBinary (float val)
{
	// A is the integer part of val
	int A = val; 
	
	// B is the float point of val
	float B = val-A;
	
	string Binary1;
	// convert the part A to Binary number
	do
	{
		Binary1 += to_string(A%2);
		A /= 2;
	}while(A);
	
	reverse(Binary1.begin(),Binary1.end());
	string Binary2 = "";
	string Binary3 = Binary1;
	B *= 2;
	
	// convert part B to Binary number
	if(B)
	{
		do
		{
		    Binary2 += to_string(int(B));
		    B -= int(B);
		    B *= 2;
		}while(B != 0.0);
		Binary3 = Binary1+"."+Binary2;
	}
	
	// The result after conversion
	cout << "Number " << val << " in Binary number is: " << Binary3 << '\n';
}
