#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main()
{
	string name = "ANameisNade";
	string n1 = name.substr(0,3);
	string n2 = name.substr(3,3);
	string n3 = name.substr(6,3);
	cout << (int(name[0]-'7')) << '\n';
	cout << n1 << " size is " << n1.length() << endl;
	cout << n2 << '\n';
	cout << n3 << '\n';
	cout << to_string('A');
	// 673.21
	// 3   7   6
	//0011  	
	return 0;
}
