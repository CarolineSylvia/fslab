//============================================================================
// Name        : lab1.cpp
// Author      : Caroline
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<fstream>

using namespace std;
fstream fp1,fp2;

void reverse(char *);
char str[30];

int main()
{
	int ch;
	cout<<"Enter your choice: 1.String reversal through terminal 2.String reversal through files" <<endl;
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"Enter the string:"<<endl;
		cin>>str;
		reverse(str);
		break;
		
		case 2: fp1.open("input.txt",ios::in);
		fp2.open("output.txt",ios::out);
		while(!fp1.eof())
		{
			fp1.getline(str,)
		}
	}
	
}
