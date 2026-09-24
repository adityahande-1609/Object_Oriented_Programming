#include<iostream>
using namespace std;
int add( int a , int b)
{
    return a+b;
}
int add (int a , int b,int c)
{
    return a + b+c;
}
double add(double a ,double b)
{
return a+b;
}
int main()
{
cout<<add(10,20)<<endl;
cout<<add(28,27,04)<<endl;
cout<<add(2.4,84.1)<<endl;
return 0;
}