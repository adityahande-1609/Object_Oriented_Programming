#include<iostream>
using namespace std;
class first
{
    protected:
    int a;
    public:
    void acc(){
        cin>> a ;
    }
};
class second:public first
{
    protected:
    int b;
    public:
    void acc1(){
        cin >> b;
    }
};
class third: public second
{
    private:
    int c;
    public:
    void acc2(){
        cin >> c;
    }
    void disp(){
        cout << "values are: "<<a<<b<<c;
    }
};
int main()
{
    third x;
    x.acc();
    x.acc1();
    x.acc2();
    x.disp();
    return 0 ;  
}
