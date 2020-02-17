#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define size 10
using namespace std;

int main(){
    int data[size];
    // create random data
    srand((unsigned int)time(NULL));rand();
    for(int i=0; i<size; i++)
        data[i]=rand()%1000;
    // print out original data
    cout<<"排序前"<<endl;
    for(int i=0; i<size; i++)
        cout<<setw(4)<<data[i];
    cout<<endl;
    // start sort
    for(int i=1; i<size; i++){
        for(int j=0; j<size-i; j++){
            if(data[j]>data[j+1]){
                int temp=data[j+1];
                data[j+1]=data[j];
                data[j]=temp;
            }
        }
        cout<<"外層迴圈跑"<<i<<"次結果為"<<endl;
        for(int i=0; i<size; i++)
            cout<<setw(4)<<data[i];
        cout<<endl;
    }
    // print out final data
    cout<<"排序後"<<endl;
    for(int i=0; i<size; i++)
        cout<<setw(4)<<data[i];
    cout<<endl;
}