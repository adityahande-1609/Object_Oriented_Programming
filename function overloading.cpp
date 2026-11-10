//function overloading
#include<iostream>
using namespace std;
class base{
	int a,b;
	public: 
		void acc(){
			cout<<"enter the vaules";
			cin>>a>>b;
		}
		void disp(){
			cout<<" \nthe values are : "<<a <<" "<<b;
		}
		void add(int y,int x){
			cout<<" \nthe sum of the two is : "<<x+y;
		}
		void add(double x,double y){
			cout<<" \nthe addition of the two floats is : "<<x+y;
		}
		void add(int x,int y,int z){
			cout<<" \nthe sum of the 3 variables is :"<<x+y+z; 
		}
};
int main(){
	base g;
	g.acc();
	g.add(2,3);
	g.add(2,3,4);
	g.add(2.5,2.5);
	g.disp();
	return 0;
}