#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// To convert Decimal Number to Hexadecimal Number
void DecimalToHexadecimal (float);

// To Get letters A,B,C,D,E,F
char TheLetter(int);

int main ()
{
	float decimal;
	char x;
	
	do
	{
		cout << "Enter Decimal number: ";
	    cin >> decimal;
		DecimalToHexadecimal(decimal);
		cout << "Try Again (y/n)? ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

char TheLetter(int num)
{
	switch(num)
	{
		case 10: return 'A';
		break;
		
		case 11: return 'B';
		break;
		
		case 12: return 'C';
		break;
		
		case 13: return 'D';
		break;
		
		case 14: return 'E';
		break;
		
		default: return 'F';
	}
}
void  DecimalToHexadecimal (float val)
{
	// A is the integer part of val
	int A = val; 
	
	// B is the float point of val
	float B = val-A;
	
	string Hexadecimal1;
	// convert the part A to Hexadecimal number
	do
	{
		if(A%16 > 9)
		{
			Hexadecimal1 += TheLetter(A%16);
		}
		else
		{
			Hexadecimal1 += to_string(A%16);
		}
		A /= 16;
	}while(A);
	
	reverse(Hexadecimal1.begin(),Hexadecimal1.end());
	string Hexadecimal2 = "";
	string Hexadecimal3 = Hexadecimal1;
	B *= 16;
	
	// convert part B to Hexadecimal number
	if(B)
	{
		do
		{   
		    if(A%16 > 9)
		    {   
			    Hexadecimal1 += TheLetter(int(B));
		    }
		    else
		    {
			    Hexadecimal1 += to_string(int(B));
	        }
		    B -= int(B);
		    B *= 16;
		}while(B != 0.0);
		
	    Hexadecimal3 = Hexadecimal1+"."+Hexadecimal2;
	}
	
	// The result after conversion
	cout << "Number " << val << " in Hexadecimal number is: " << Hexadecimal3 << '\n';
}
