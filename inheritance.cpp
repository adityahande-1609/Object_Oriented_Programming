#include<iostream>
using namespace std;
class person{
	public :
		char n[20];
		int ssno;
	public:
	void acc()
	{
		cout<<"enter the name and ssno:\n";
		cin>>n>>ssno;
		cout<<"\n enter Account no and bank balance:";
	}
}h[5];
class bank:protected person{
	int a,b;
	public: 
	void accept()
	{
		acc();
		cin>>a>>b;
	}
	void display()
	{
		cout<<"name : "<<n<<"\nsocial security no: "<<ssno<<"\n account no: "<<a<<"\nblack number :"<<b;
	}
};
int main()
{
	bank c[5];
	for(int i=0;i<2;i++)
	{
		c[i].accept();
	}
	for(int i=0;i<2;i++){
		cout<<"\n\n"<<"person :"<<i+1<<"\n";
		c[i].display();
	}
	return 0;	
}
