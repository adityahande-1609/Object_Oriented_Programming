#include<iostream>
using namespace std;
class shape{
	private:
		int a;
		static float pi;
	public:
		void get(){
			cout<<"enter the radius of:\n";
			cin>>a;
		}
        void area(){
		cout<< a*a*pi;
	}
        void disp(){
        	cout<<"\n\nPIE value is : "<<pi;
		}
};
float shape::pi=3.14;
int main()
{
	shape c;
	c.get();
	c.area();
	c.disp();
	return 0;	
}
