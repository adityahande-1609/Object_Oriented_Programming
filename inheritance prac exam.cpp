#include<iostream>
using namespace std;
class base{
	protected:
		int a,b;
	public:
		base(){
			a=10;
			b=20;
		}
		void acc(){
			cout<<"\nenter the values of a &b : ";
			cin>>a >>b;
		}
		void disp(){
			cout<<"\nthe values are : \n a: "<<a<<"\nb: "<<b;
		}
};
class derived:public base{
	public:
		void disp1(){
		cout << " \nthis is the derived class ";
		}
	
};
int main(){
	derived d;
	d.disp();
	d.acc();
	d.disp();
	d.disp1();
	return 0;
}