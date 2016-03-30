//============================================================================
// Name        : lab2.cpp
// Author      : caroline
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Student
{
    public:
        string usn,name,sem;
        void read();
        void display();
        void pack();
        void unpack();
        void modify();
}s[100],temp;

fstream fp;
void search();

int main()
{
    int ch;
    while(1)
    {
        cout<<"\n1.Insert a record\n2.Search and modify a record\n3.Exit\nEnter your choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1: temp.read();
                    fp.open("in.txt",ios::out|ios::app);
                    temp.pack();
                    fp.close();
                    break;
            case 2: search();
                    break;
            default: exit(0);        
        }
    }
}

void Student::read()
{
    cout<<"\nEnter usn: ";
	cin>>usn;
	cout<<"\nEnter name: ";
	cin>>name;
	cout<<"\nEnter sem: ";
	cin>>sem;
}

void Student::pack()
{
    string buf=usn+"|"+name+"|"+sem+"|";
    if(buf.length()>50)
    {
        printf("Error: Data exceeds record length\n");
        return;
    }
    while(buf.length()<51)
        buf=buf+"_";
    fp<<buf<<endl;
}

void search()
{
    string key;
    int s_flag=-1,count,m_flag=-1,i=0;
    cout<<"\nEnter the USN of the student to be found: ";
	cin>>key;
	fp.open("in.txt",ios::in);
	while(fp)                    //unpacks all records in the file and stores in objects
	{
	    s[i].unpack();
	    i++;
	}
	fp.close();
	count=i;
	for(i=0;i<count;i++)
	{
	    if(s[i].usn==key)
	    {
	        s_flag==i;
	        break;
	    }
	}    
	if(s_flag==-1)
	{
	    cout<<"Record not found.\n";
	    return;
	}
    cout<<"Record found\n";
    s[s_flag].display();
    cout<<"\nDo you wish to modify the Record??\n Press 1. to modify, 0. to Cancel\n";
	cin>>m_flag;
	if(m_flag)
	{
	   s[s_flag].modify();
	   fp.open("in.txt",ios::out);
	   for(i=0;i<count;i++)
		 s[i].pack();
	   fp.close();
	}
}

void Student::unpack()
{
		string seg;
		getline(fp,usn,'|');
		getline(fp,name,'|');
		getline(fp,sem,'|');
		getline(fp,seg);			
}

void Student::display()
{
	cout<<"\nName: "<<name<<"\nUSN: "<<usn<<"\nSem: "<<sem<<endl;
} 

void Student::modify()				
{
	int choice;	
	while(1)
	{	
		cout<<"\nEnter the field to modify:\n 1. name\n 2.usn \n 3.sem \n 4. to exit modification\n";
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"\nEnter new name: ";
				cin>>name;
				break;
			case 2:	cout<<"\nEnter new usn: ";
				cin>>usn;
				break;
			case 3: cout<<"\nEnter new sem: ";
				cin>>sem;
				break;
			default: return;
		}
	}
}

