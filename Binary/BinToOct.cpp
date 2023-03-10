#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// To convert Binary Number To Octal Number
void BinaryToOctal(string);

int main()
{
	string Binary;
	char x;
	
	do
	{
		cout << "Enter Binary Number: ";
		cin >> Binary;
		BinaryToOctal(Binary);
		cout << "Do You want try again (y/n): ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

void BinaryToOctal(string val)
{
	string A="", B="", threeNum;
	string Octal1 = "", Octal2 = "";

	for(int i=0; i<val.length(); i++)
	{
		if(val[i] == '.')
		{
			// A is the integer part
			A = val.substr(0,i);
			
			// B is the float part
			B = val.substr(i+1,val.length()-i);
			break;
		}
		else
		{
			// if the Number is integer only
			A = val;
		}
	}
     
    // convert the A part
    int j;
    int Num;
    reverse(A.begin(),A.end());
    for(int i=0; i<A.length(); i+= 3)
    {
    	Num = 0;
    	j = 0;
    	threeNum = A.substr(i,3);
    	if(threeNum.length() == 2)
    	{
    		threeNum += '0'; 
		}
		else if(threeNum.length() == 1)
		{
			threeNum += "00";
		}
		while(j < 3)
    	{
    		threeNum[j] == '1'? Num += pow(2,j) : 0;
    		++j;
		}
		Octal1 += to_string(Num);
	}
	reverse(Octal1.begin(),Octal1.end());
	
	// convert the B part
	for(int i=0; i<B.length(); i+=3)
	{
		Num = 0;
		j = 0;
		threeNum = B.substr(i,3);
		if(threeNum.length() == 2)
		{
			threeNum += '0';
		}
		else if(threeNum.length() == 1)
		{
			threeNum += "00";
		}
		reverse(threeNum.begin(),threeNum.end());
		while(j < 3)
		{
			threeNum[j] == '1'? Num += pow(2,j) : 0;
			++j;
		}
		Octal2 += to_string(Num);
	}
	string Octal3;
	Octal2!="" ? Octal3=Octal1+'.'+Octal2 : Octal3=Octal1;
	 
	// the result of conversion
	cout << "The Number " << val << " in Octal Number is " << Octal3 << endl;
}
