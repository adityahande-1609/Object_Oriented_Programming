#include <iostream>
using namespace std;
class demo
{
private:
    int a;
public:
    int add(demo d1, demo d2)
	{
        return d1.a + d2.a;
    }
    void get1() 
	{
        cin >> a;
        cout <<"number entered: "<< a << endl;
    }
};
int main() {
    demo t1, t2, t3;
    t1.get1();
    t2.get1();
    int result = t3.add(t1, t2);
    cout << "Sum: " << result << endl;
    return 0;
}

