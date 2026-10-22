#include<iostream>
#include<fstream>
using namespace std ;
int main()
{
	string name;
	fstream test("data.txt");
	while(!test.eof()){
		test>>name;
	    cout<<"\n name is:"<<name;
	}
	test.close();
	return 0;
}
