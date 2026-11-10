//operator overloading 
#include<iostream>
using namespace std;
class base{
	public:
		int a ,b;
		void acc(){
			cout<<"enter the values :";
			cin>>a>>b;
		}
		void disp(){
			cout<<"values are : "<<a<<" "<<b;
		}
		base operator +(base d){
			base t;
			t.a = a +d.a;
			t.b = b +d.b;
			return t;
		}
		base operator ++(){
			++a;
			++b;
		}
};
int main (){
	base a,b,c;
	a.acc();
	b.acc();
	c= a+b;
	c.disp();
	++c;
	cout<<"incremented\n";
	c.disp();
	return 0;
}