#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct stu{
	char name[40];
	int math;
	int en;
};

int main(){
	stu a,b;
	char myname[5]="John";
	memcpy(a.name,myname,sizeof(myname));
	a.math=99;
	a.en=85;
	memcpy(&b,&a,sizeof(a));
	cout<<b.name<<" "<<b.math<<" "<<b.en<<endl;
}
