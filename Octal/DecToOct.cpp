#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// To convert Decimal Number to Octal Number
void DecimalToOctal (float);

int main ()
{
	float decimal;
	char x;
	
	do
	{
		cout << "Enter Decimal number: ";
	    cin >> decimal;
		DecimalToOctal(decimal);
		cout << "Try Again (y/n)? ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

void  DecimalToOctal (float val)
{
	// A is the integer part of val
	int A = val; 
	
	// B is the float point of val
	float B = val-A;
	
	string Octal1;
	// convert the part A to Octal number
	do
	{
		Octal1 += to_string(A%8);
		A /= 8;
	}while(A);
	
	reverse(Octal1.begin(),Octal1.end());
	string Octal2 = "";
	string Octal3 = Octal1;
	B *= 8;
	
	// convert part B to Octal number
	if(B)
	{
		do
		{
		    Octal2 += to_string(int(B));
		    B -= int(B);
		    B *= 8;
		}while(B != 0.0);
		Octal3 = Octal1+"."+Octal2;
	}
	
	// The result after conversion
	cout << "Number " << val << " in Octal number is: " << Octal3 << '\n';
}
