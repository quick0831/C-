#include <iostream>
using namespace std;

int main(){
	int a=0b01001101;
	int b=0b00100110;
	cout<<"a="<<hex<<a<<endl;
	cout<<"b="<<hex<<b<<endl;
	cout<<"a&b="<<hex<<(a&b)<<endl;
	cout<<"a|b="<<hex<<(a|b)<<endl;
	cout<<"a^b="<<hex<<(a^b)<<endl;
	cout<<"~a="<<hex<<(~a)<<endl;
	cout<<"(a<<1)="<<hex<<(a<<1)<<endl;
	cout<<"(a>>1)="<<hex<<(a>>1)<<endl;
}
