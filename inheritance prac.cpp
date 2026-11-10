// single inheritance using a base class Person with data members name and age and a derived class Employee with data members and department.
#include<iostream>
using namespace std;
class Person{
	protected:
		char name[20];
		int age;
	public:
		void getin(){
			cout<<"Enter the person's name and age:";
			cin>>name >>age;
		}
};
class Employee:public Person{
	private:
		char department[40];
	public:
		void acc(){
			cout<<"Enter Department:";
			cin>>department;
		}
		void disp(){
			cout<<"info is :\nName"<<name<<"\nAge:"<<age<<"\nDepartment:"<<department;
		}
}e;
int main()
{
	e.getin();
	e.acc();
	cout<<"\n\n";
	e.disp();
	return 0;
}