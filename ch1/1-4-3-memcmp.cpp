#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
	char tmp1[12]="I love C++!";
	char tmp2[13]="I love Java!";
	int n;
	n=memcmp(tmp1,tmp2,sizeof(tmp1));
	cout<<tmp1;
	if(n>0) cout<<"大於";
	else if(n<0) cout<<"小於";
	else cout<<"等於";
	cout<<tmp2<<endl;
}
