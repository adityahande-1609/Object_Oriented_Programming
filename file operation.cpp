#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char name[20];
	cout<<"Enter your name:";
	cin>>name;
	fstream newfile("data.txt");
	newfile<<name;
	cout<<"\n data stored";
	newfile.close();
	return 0; 
}