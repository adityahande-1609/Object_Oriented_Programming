#include<iostream>
using namespace std;
class student
{
	private:
		int r,prn;
		char n[20];
	public:
		void acc();
		void out(); 
};
int main ()
{
	int i;
	student s[2];
	for(i=0;i<2;i++)
	{
		cout<<"enter the details\n";
		s[i].acc();
	}
	cout<<"complete\n\n";
	for(i=0;i<2;i++)
	{
		cout<<"Details are : "<<endl;
		s[i].out();
	}
	return 0;
}
void student::acc()
{
	cout<<"enter the name:\n";
	cin>>n;
	cout<<"enter PRN no\n";
	cin>>prn;
	cout<<"enter Roll no\n";
	cin>>r;
}
void student::out()
{
	cout<<"name is: "<<n<<endl;
	cout<<"Prn no: "<<prn<<endl;
	cout<<"Roll no: "<<r<<endl;
}
