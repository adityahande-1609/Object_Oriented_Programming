#include<iostream>
using namespace std;
class student{
	private:
		char a[20];
	public:
		void get(){
			cout<<"enter  name :\n";
			cin>>a;
		}
		void disp(student s){
			cout<<"name of student is : "<<s.a;
		}
};
int main ()
{
	student s1;
	s.get();
	s.disp(s1);
	return 0;
}
