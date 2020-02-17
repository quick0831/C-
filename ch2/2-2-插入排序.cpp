#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define size 10
using namespace std;

bool swap(int *data, int a, int b){
    if(data[a]<=data[b])
        return false;
    if(a<0 || b<0)
        return false;
    int temp=data[a];
    data[a]=data[b];
    data[b]=temp;
    return true;
}

int main(){
    int data[size],insert;
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
    insert=1; // the second object
    while(insert<size){
        int pointer=insert;
        while(swap(data, pointer-1, pointer))
            pointer--;
        cout<<"外層迴圈跑"<<insert<<"次結果為"<<endl;
        for(int i=0; i<size; i++)
            cout<<setw(4)<<data[i];
        cout<<endl;
        insert++;
    }
    // print out final data
    cout<<"排序後"<<endl;
    for(int i=0; i<size; i++)
        cout<<setw(4)<<data[i];
    cout<<endl;
}