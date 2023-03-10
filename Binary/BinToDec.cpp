#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// To convert Binary Number to Decimal Number
void BinaryToDecimal (string);

int main ()
{
	string Binary;
	char x;
	
	do
	{
		cout << "Enter Binary number: ";
	    cin >> Binary;
		BinaryToDecimal(Binary);
		cout << "Try Again (y/n)? ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

void BinaryToDecimal (string val)
{
	double Decimal = 0;
	
	// A is the integer part & B is the float part
	string A,B;
	int j = 0;

	for(int i=0; i<val.length(); i++)
	{
		if(val[i] == '.')
		{
			// A is the integer part
			A = val.substr(0,i);
			
			// B is the float part
			B = val.substr(i+1,val.length()-val[i]);
			break;
		}
		else
		{
			// if the value only integer number
			A += val[i];
		}
	}
	
	// convert the integer part only 'A'
	for(int i=A.length(); i>0; i--)
	{
		A[i-1] == '1'? Decimal += pow(2,j) : 0;
		++j; 
	}
	
	// convert the float part only 'B'
	if(B != "")
	{
		j = 1;
		for(int i=0; i<B.length(); i++)
		{
			B[i] == '1'? Decimal += 1/pow(2,j) : 0;
			++j;
		}	
    }
	
	// The result after conversion
	cout << "Number " << val << " in Decimal number is: " << Decimal << '\n';
}
