#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// To convert Octal Number to Decimal Number
void OctalToDecimal(string);

int main()
{
	string Octal;
	char x;
	
	do
	{
		cout << "Enter Octal number: ";
	    cin >> Octal;
		OctalToDecimal(Octal);
		cout << "Try Again (y/n)? ";
		cin >> x;
	}while(x == 'y');
	
	
	return 0;
}

void OctalToDecimal(string val)
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
		Decimal += int(A[i-1]-'0')*pow(8,j);
		++j; 
	}
	
	// convert the float part only 'B'
	if(B != "")
	{
		j = 1;
		for(int i=0; i<B.length(); i++)
		{
			Decimal += int(B[i]-'0')*(1/pow(8,j));
			++j;
		}	
    }
	
	// The result after conversion
	cout << "Number " << val << " in Decimal number is: " << Decimal << '\n';
}
