//============================================================================
// Name        : fl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
fstream fp;
char *fname;
 class Student{
        string name,usn,branch;
        int sem;
public:
                void read(){
                        cout<<"Enter the name";
                        cin>>name;
                        cout<<"Enter the usn";
                        cin>>usn;
                        cout<<"Enter the sem";
                        cin>>sem;
                        cout<<"Enter the branch";
                        cin>>branch;

}

                void pack(char *fname){
                        string buffer;
                        fp.open(fname,ios::out);
                        stringstream ss;
                        ss<<name<<"|"<<usn<<"|"<<sem<<"|"<<branch;
                        buffer=ss.str();
                        fp<<buffer;
                        fp.close();
                }
                void unpack(char *fname){
                        string extra;
                        fp.open(fname,ios::in);
                        getline(fp,extra);
                };
                void modify(){};
                void search(){};

} ;




 int main() {
         int ch;
         Student s1;
         cout<< "Enter your choice:"
                         "1.pack 2.unpack 3.modify 4.search 5.exit";
         cin>>ch;
         switch(ch)
         {
                 case 1:s1.read();
                            cout<<"Enter the file name to pack data into:";
                            cin>>fname;
                            s1.pack(fname);
                            break;
                 case 2:s1.unpack();
                            break;
                 case 3:s1.modify();
                            break;
                 case 4:cout<<"Enter element to search for";


         }
         return 0;
 }