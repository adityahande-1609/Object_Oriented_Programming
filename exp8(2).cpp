#include<iostream>
using namespace std; 
class student{
    public :
    float marks ;
};
int main()
{
    float sum, avg ;
    student s[5];
    for ( int i=0;i<5;i++){
        cin >> s[i].marks;
        sum +=s[i].marks;
    }
    avg = sum /5;
    cout<< " average : "<< avg;
    return 0;
}
