#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// To convert Octal Number To Binary Number
void OctalToBinary(string);

int main()
{
	string Octal;
	char x;
	
	do
	{
		cout << "Enter Octal Number: ";
		cin >> Octal;
		OctalToBinary(Octal);
		cout << "Do You want try again (y/n): ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

void OctalToBinary(string val)
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
		Num = int(A[i]-'0');
		while(j < 3)
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
		Num = int(B[i]-'0');
		while(j < 3)
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
