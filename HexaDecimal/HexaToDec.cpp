#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// To convert Hexadecimal Number to Decimal Number
void HexadecimalToDecimal(string);

int main()
{
	string hexaDecimal;
	char x;
	
	do
	{
		cout << "Enter HexaDecimal number: ";
	    cin >> hexaDecimal;
		HexadecimalToDecimal(hexaDecimal);
		cout << "Try Again (y/n)? ";
		cin >> x;
	}while(x == 'y');

	return 0;
}

void HexadecimalToDecimal(string val)
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
		if(A[i-1] >= '0' && A[i-1] <= '9')
		{
			Decimal += int(A[i-1]-'0')*pow(16,j);
		}
			
		// if the part A has Letters like A, B, C, D, E, F 
		else
		{
			Decimal += int(A[i-1]-'7')*pow(16,j);
		}
		++j; 
	}
	
	// convert the float part only 'B'
	if(B != "")
	{
		j = 1;
		for(int i=0; i<B.length(); i++)
		{
			if(B[i] >= '0' && B[i] <= '9')
			{
				Decimal += int(B[i]-'0')*(1/pow(16,j));
			}
			
			// if the part B has Letters like A, B, C, D, E, F 
			else
			{
				Decimal += int(B[i]-'7')*(1/pow(16,j));
			}
			++j;
		}	
    }
	
	// The result after conversion
	cout << "Number " << val << " in Decimal number is: " << Decimal << '\n';
}
