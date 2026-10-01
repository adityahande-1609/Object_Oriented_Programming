#include<iostream>
using namespace std;
class base 
{
	protected:
		int a ,b ,c;
	public:
		void acc(){
			cout << " enter vals of a,b,c:\n";
			cin>>a>>b>>c;
		}
		void show(){
			cout<<"the vals are:"<<a;
			cout<<" "<<b;
			cout<<" "<<c<<endl;
		}
};
class der:public base{
	public:
	void show(){
		cout << "\n this is der fun:";
	}
};
int main()
{
	base a;
	der b;
	a.acc();
	a.show();
	b.show();
	return 0;
}
