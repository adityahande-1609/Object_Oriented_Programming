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
};
class derived:public base{
	public:
	void disp(){
		cout<<a<<b;
	}
};
int main()
{
	derived d;
	d.disp();
	return 0;
}