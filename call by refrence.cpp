#include <iostream>
using namespace std;
class demo {
public:
    int a, b;
    void get(int x, int y) {
        a = x;
        b = y;
    }
    int add() {
        return a + b;
    }
    void swap(demo r) {
        int t;
        t = r.a;
        r.a = r.b;
        r.b = t;
        cout << "\nNew num 1: " << r.a;
        cout << "\nNew num 2: " << r.b;
    }
};
int main() {
    demo d, d1;
    int w, e;
    cout << "Enter 2 variables: ";
    cin >> w >> e;
    d.get(w, e);
    int sum = d.add();
    cout << "\n\nSum: " << sum;
    d.swap(d);
    return 0;
}
