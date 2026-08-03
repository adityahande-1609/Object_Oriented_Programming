#include<iostream>
using namespace std;
class rec
{
	int l,b;
	public:
	void acc();	
	void ar();	
		
};
void rec::acc()
{
	cout<<"enter length and breath: \n";
	cin>>l>>b;
}
void rec::ar()
{
	cout<<"area is : "<<l*b;
}
int main()
{
	rec r1;
	r1.acc();
	r1.ar();
	return 0;
}
