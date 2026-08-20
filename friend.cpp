#include <iostream>
using namespace std;
class stud1;
class student {
private:
    int r;
    char n[20];
public:
    void get() {
        cin >> n >> r;
    }
    friend void disp(student s, stud1 a);
};
class stud1 {
private:
    int prn;
    char nm[20];
public:
    void get1() {
        cin >> nm >> prn;
    }
    friend void disp(student s, stud1 a);
};
void disp(student s, stud1 a) {
    cout << "Student 1 Name: " << s.n << "\nRoll number: " << s.r << endl;
    cout << "Stud1 Name: " << a.nm << "\nPRN: " << a.prn << endl;
}
int main() {
    student s1;
    stud1 a1;
    cout << "Enter name and roll number for Student:\n";
    s1.get();
    cout << "Enter name and PRN for Stud1:\n";
    a1.get1();
    disp(s1, a1);

    return 0;
}
