#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 100
using namespace std;

int main(){
	int a[100];
	const double PI=acos(-1.0);
	for(int i=0;i<MAX;i++){
		a[i]=i;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<setprecision(15)<<PI<<endl;
}
