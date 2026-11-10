//inheritance for hybrid of multilevel and multiple along with virtual class 
#include<iostream>
using namespace std;
class a{
	protected:
		int e,f;
	public:
		void acc(){
			cout <<"enter the values of 2 variables: ";
			cin>>e>>f;
			}
};
class b:virtual public a{
	public :
		void disp(){
			cout << "this is the first derived class";
		}
};
class c:virtual public a{
	public:
		void disp1(){
			cout<<"this is the second derived class";
		}
};
class d:public b,public c{
	public:
		void disp2(){
			cout<<"this variable was inherited fro mthe first base class";
			cout<<"\n variables:\na: "<<e<<"\nb:"<<f;
		}
};

int main (){
	d x;
	x.acc();
	x.disp();
	x.disp1();
	x.disp2();
}