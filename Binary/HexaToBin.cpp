#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// To convert Hexadecimal Number To Binary Number
void HexadecimalToBinary(string);

int main()
{
	string Hexadecimal;
	char x;
	
	do
	{
		cout << "Enter Hexadecimal Number: ";
		cin >> Hexadecimal;
		HexadecimalToBinary(Hexadecimal);
		cout << "Do You want try again (y/n): ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

void HexadecimalToBinary(string val)
{
	string A, B;
	string Binary1="", Binary2="";
	
	for(int i=0; i<val.length(); i++)
	{
		if(val[i] == '.')
		{
			// A is the integer Part
			A = val.substr(0,i);
			
			// B is the float Part
			B = val.substr(i+1,val.length()-i);
			break;
		}
		else
		{
			// if the number is integer only
			A = val;
		}
	}
	
	reverse(A.begin(),A.end());
	int j, Num;
	
	// To convert Part A to Binary Number 
	for(int i=0; i<A.length(); i++)
	{
		j = 0;
		if(A[i]>='A' && A[i]<='F')
		{
			Num = int(A[i]-'7');
		}
		else
		{
			Num = int(A[i]-'0');
		}
		while(j < 4)
		{
			Binary1 += to_string(Num%2);
			Num /= 2;
			++j;
		}
	}
	reverse(Binary1.begin(),Binary1.end());
	
	// convert Part B to Binary Number
	string part;
	for(int i=0; i<B.length(); i++)
	{
		j = 0;
		part="";
		if(B[i]>='A' && B[i]<='F')
		{
			Num = int(B[i]-'7');
		}
		else
		{
			Num = int(B[i]-'0');
		}
		while(j < 4)
		{
			part += to_string(Num%2);
			Num /= 2;
			++j;
		}
		reverse(part.begin(),part.end());
		Binary2 += part;
	}
	
	string Binary3;
	Binary2!="" ? Binary3=Binary1+'.'+Binary2 : Binary3=Binary1;
	 
	// the result of conversion
	cout << "The Number " << val << " in Binary Number is " << Binary3 << endl;
}
