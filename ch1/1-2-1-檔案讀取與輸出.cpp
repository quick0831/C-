#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s;
	while(getline(in,s)){
		out<<s<<endl;
	}
}
