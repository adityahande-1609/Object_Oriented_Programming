//bank account and balance
#include<iostream>
using namespace std;
class account{
	int ac_n;
	float b;
	public:
		void acc();
		void disp();
};
void account::acc(){
			cout<<"enter the account number:";
			cin>>ac_n;
			cout<<"enter the accoutn balance:";
			cin>>b;
		}
void account::disp(){
	cout<< "account balance is : "<<b;
}
int main()
{
	account a;
	a.acc();	
	cout<<"\n\n";
	a.disp();	
	return 0;
}
