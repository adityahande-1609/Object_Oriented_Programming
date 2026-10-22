#include<iostream>
#include<fstream>
using namespace std ;
int main()
{
	string name;
	fstream test("data.txt");
	test>>name;
	cout<<"name is:"<<name;
	test.close();
	return 0;
}