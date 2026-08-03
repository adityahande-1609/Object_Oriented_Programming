#include<iostream>
using namespace std;
class product{
	int p_id;
	char pn[20];
	public:
	void acc();	
	void disp();	
};
void product::acc(){
	cout<<"enter the product id: ";
	cin>>p_id;
	cout<<"enter the product name: ";
	cin>>pn;
}
void product::disp(){
	cout<<"Product id: "<<p_id;
	cout<<"\nProduct name : "<<pn;
}
int main()
{
	product p;
	p.acc();
	cout<<"\n\n";
	p.disp();
return 0;	
}
