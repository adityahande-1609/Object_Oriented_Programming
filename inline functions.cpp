#include<iostream>
float pi =3.14;
using namespace std; 
inline int cube(int a)
{
	return a*a*a;
}
inline int lar(int a,int b)
{
	if(a<b){
		return b;
	}
	else{
		return a;
	}
}
inline float car(int a)
{
	float ar;
	ar =pi*a*a;
	return ar;
}
inline float si(int m,float r,float c){
	float i=((r/100)*c)*m;
	return i;
}
inline void swap(){
	int t,a,b;
	cin>>a>>b;
	t=a;
	a=b;
	b=t;
	cout<<"\n new num 1 :"<<a<<"\n new num2: "<<b;
}
int main()
{
	float ar,r,c;
	int a,a1,a2,m;
	cout<<"enter number";
	cin>>a;
	cout<<" the cube is : "<<cube(a);
	cout<<"\n\n\nEnter 2 numbers:";
	cin>>a1>>a2;
	cout<<"\nthe larger number is : "<<lar(a1,a2);
	cout<<"\nenter the radius :";
	cin>>a;
	ar=car(a);
	cout<<"\n Area of the circle is: "<<car(a); 
	cout<<"\n\n enter the capital , rate and time period (in months): ";
	cin >>c>>r>>m;
	cout<<"simple interst will be : "<<si(m,r,c); 
	cout<<"\nenter 2 nums";
	swap();
	
	return 0;
}
