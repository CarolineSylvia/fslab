//============================================================================
// Name        : lab4.cpp
// Author      : caroline
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

class Student
{
	public: string usn,name,sem;
			void read();
			void display();
			void pack();
			void unpack(int pos);
}temp;
fstream fp;
int rrn_l[100];
void search(int rec_no);

int main()
{
	int ch,rec_no;
	while(1)
	{
		cout<<"1.Insert\n 2.Search using RRN \n3.Exit\n Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:temp.read();
				   temp.pack();
				   break;
			case 2:cout<<"Enter record number to search";
				   cin>>rec_no;
				   search(rec_no);
				   break;
			default: exit(0);
		}
	}
}

void Student::read()
{
		cout<<"Enter the USN:";
		cin>>usn;
		cout<<"Enter the name:";
	    cin>>name;
		cout<<"Enter the sem:";
		cin>>sem;
}

void Student::pack()
{
		string buf;
		int pos,i=0;
		fp.open("in.txt",ios::out|ios::app);
		pos=fp.tellp();
		buf=usn+"|"+name+"|"+sem+"$";
		fp<<buf;
		fp.close();
}

void Student::display()
{
		cout<<"\nUSN:"<<usn<<"\nName:"<<name<<"\nSem:"<<sem<<"\n";
}

void Student::unpack(int pos)
{
		fp.seekg(pos,ios::beg);
		getline(fp,usn,'|');
		getline(fp,name,'|');
		getline(fp,sem,'$');
		fp.close();
}

void search(int rec_no)
{
		int pos,ch;
		pos=rrn_l[rec_no];
		fp.open("in.txt",ios::in);

		temp.unpack(pos);
		temp.display();
		return ;
}
