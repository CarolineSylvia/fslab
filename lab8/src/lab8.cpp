//============================================================================
// Name        : lab8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

string merge(vector<string> fn,int l,int r); 

int main()
{
	vector<string> fn;
	fn.push_back("f0.txt");
	fn.push_back("f1.txt");
	fn.push_back("f2.txt");
	fn.push_back("f3.txt");
	fn.push_back("f4.txt");
	fn.push_back("f5.txt");
	fn.push_back("f6.txt");
	fn.push_back("f7.txt");
	return merge(fn,0,7);
}

string merge(vector<string> fn,int l,int r)
{	
	string nf;
	ofstream of;
	ifstream if1,if2;
	if(l==r) { nf<<fn; return nf;}
	
	else if(r-l==1)
	{
		 
		string s1,s2;
		if1(fn[0].c_str());
		if2(fn[1].c_str());
		
		while(!if1.eof()&&!if2.eof())
		{	
			string s1,s2;
			getline(if1,s1)
			getline(if2,s2)
			if(s1<s2){ of<<s1; nf=of.c_str(); }
			else if(s1==s2) {of<<s1; nf=of.c_str(); }
			else
			{
				of<<s2;
				nf=of.c_str(); 
			}
		}
		
		while(if1)
		{
			of<<s1;
			nf=of.c_str(); 
		}
			
		while(if2)
		{
			of<<s2;
			nf=of.c_str(); 
		}
	}	
		
	else
	{	
		string f1,f2,f3;
		vector<string> v;
		int mid=0;
		mid=(l+r)/2;
		f1=merge(fn,l,mid);
		f2=merge(fn,mid+1,r);
		v.push_back(f1,f2);
		f3=merge(v,0,1);
		nf=f3;
	}	
	if1.close();
	if2.close();
	
	return nf;
}	
