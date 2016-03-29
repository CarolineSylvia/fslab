//============================================================================
// Name        : lab7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class filelist
{
	string l1[100],l2[100];
public: void matching();
		void load();

}c;

void sort(string *l,int n);

void filelist::void load()
{
		int c1=0,c2=0;
		fstream fp1,fp2;
		string buffer;
		fp1.open("data1.txt",ios::in);
		while(fp1.eof())
		{
				getline(fp1,buffer);
				l1[++c1]=buffer;

		}
		sort(l1,c1);
		fp2.open("data2.txt",ios::in);
		while(fp2.eof())
		{
				getline(fp2,buffer);
				l1[++c2]=buffer;
		}
		sort(l2,c2);
}

void sort(string *l,int n)
{ 	string temp;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=i=1;j<=n;j++)
		{
			if(l[i]<l[j])
			{
				temp=l[i];
				l[i]=l[j];
				l[j]=temp;
			}
		}
	}
}
