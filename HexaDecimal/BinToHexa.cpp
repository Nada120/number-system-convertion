#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// To convert Binary Number To HexaDecimal Number
void BinaryToHexaDecimal(string);

// To convert Binary Number To letter A, B, C, D, E, F
char ToLetter(int);

int main()
{
	string Binary;
	char x;
	
	do
	{
		cout << "Enter Binary Number: ";
		cin >> Binary;
		BinaryToHexaDecimal(Binary);
		cout << "Do You want try again (y/n): ";
		cin >> x;
	}while(x == 'y');
	
	return 0;
}

char ToLetter(int num)
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

void BinaryToHexaDecimal(string val)
{
	string A="", B="", threeNum;
	string Hexa1 = "", Hexa2 = "";

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
    for(int i=0; i<A.length(); i+= 4)
    {
    	Num = 0;
    	j = 0;
    	threeNum = A.substr(i,4);
    	if(threeNum.length() == 3)
		{
			threeNum += '0';
		}
		else if(threeNum.length() == 2)
		{
			threeNum += "00";
		}
		else if(threeNum.length() == 1)
		{
			threeNum += "000";
		}
		while(j < 4)
    	{
    		threeNum[j] == '1'? Num += pow(2,j) : 0;
    		++j;
		}
		Num >= 10 ? Hexa1 += ToLetter(Num) : Hexa1 += to_string(Num);
	}
	reverse(Hexa1.begin(), Hexa1.end());
	
	// convert the B part
	for(int i=0; i<B.length(); i+=4)
	{
		Num = 0;
		j = 0;
		threeNum = B.substr(i,4);
		if(threeNum.length() == 3)
		{
			threeNum += '0';
		}
		else if(threeNum.length() == 2)
		{
			threeNum += "00";
		}
		else if(threeNum.length() == 1)
		{
			threeNum += "000";
		}
		reverse(threeNum.begin(),threeNum.end());
		while(j < 4)
		{
			threeNum[j] == '1'? Num += pow(2,j) : 0;
			++j;
		}
		Num >= 10 ? Hexa2 += ToLetter(Num) : Hexa2 += to_string(Num);
	}
	string Hexa3;
	Hexa2!="" ? Hexa3=Hexa1+'.'+Hexa2 : Hexa3=Hexa1;
	 
	// the result of conversion
	cout << "The Number " << val << " in HexaDecimal Number is " << Hexa3 << endl;
}
