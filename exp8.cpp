#include<iostream>
using namespace std;
class EMP{
    public:
    int id;
    string name;
    void disp(){
        cout<< id<<" "<<name<<endl;
    }
    void acc(){
        cin>>id>>name; 
    }
};
int main()
{
    EMP e[5];
    for (int i=0; i<5;i++){
        e[i].acc();
    }
    cout<<"\n Display:\n";
    for (int i=0; i<5;i++){
        e[i].disp();
    }
    return 0;
}
