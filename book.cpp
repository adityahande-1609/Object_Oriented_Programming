#include<iostream>
using namespace std;
class book{
	char au_n[20],b_n[30];
	int b_i,b_p;
	
	public:
		void acc();
		void disp();
};
void book::acc(){
	cout<<"enter author name: \n";
	cin>>au_n;
	cout<<"enter book name: \n";
	cin>>b_n;
	cout<<"enter book index: \n";
	cin>>b_i;
	cout<<"enter book price: \n";
	cin>>b_p;
}
void book::disp(){
	cout<<"Author name: "<<au_n<<"\nbook name: "<<b_n;
	cout<<"\nbook index: "<<b_i<<"\nbook pirce: "<<b_p;
}
int main()
{
	int i;
	book b[2];
	for(i=0;i<2;i++){
		b[i].acc();
	}
	cout<<"\n\n";
	for(i=0;i<2;i++){
	b[i].disp();	
	}
	return 0;
}
