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
int main()
{
	float ar;
	int a,a1,a2;
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
	return 0;
}
