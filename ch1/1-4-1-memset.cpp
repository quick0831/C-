#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){
	int a[100];
	memset(a,0,sizeof(a));
	for(int i=0;i<100;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
