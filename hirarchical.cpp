#include<iostream>
using namespace std;
class first{
	protected:
		int a;
		int b;
	public:
		first(){
			a=10;
			b=20;
		}
};
class second:public first{
	public:
		void disp(){
		cout<<"value a: "<<a;
	}
};
class third:public first{
	public:
		void disp1(){
		cout<<"value b: "<<b;
	}
};
int main(){
	second x;
	third y;
	x.disp();
	y.disp1();
	return 0;
}
