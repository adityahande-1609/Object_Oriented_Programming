//constructor and its types
#include<iostream>
using namespace std;
class base {
	int a,b;
	public :
		base(int x=10,int y=20){
			a =x;
			b=y;
		}
		~base(){
			cout<<"\ndistroyed ";
		}
		void disp(){
			cout<<"\nvalues : "<<a<<" "<<b;
		}
};
int main(){
	base f;
	f.disp();
	base g(22,44);
	g.disp();
	return 0;
}
