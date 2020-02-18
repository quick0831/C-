#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define size 10
using namespace std;

void print(int *data){
    for(int i=0; i<size; i++)
        cout<<setw(4)<<data[i];
    cout<<endl;
};

void quick_sort(int *data, int start, int end){
    int len=end-start;
    if(len<2) return;
    if(len==2){ // 2 elements
        if(data[start]>data[start+1]){
            int temp=data[start];
            data[start]=data[start+1];
            data[start+1]=temp;
        }
        return;
    }
    // more than 2 elements
    // split to 2
    int i=start+1,j=end-1;
    int &first=data[start];
    // pre run
    while(data[i]<=first) i++;
    while(data[j]>=first) j--;
    while(i<=j){
        int temp=data[i];
        data[i]=data[j];
        data[j]=temp;
        while(data[i]<=first) i++;
        while(data[j]>=first) j--;
    }
    int temp=data[j];
    data[j]=first;
    first=temp;
    cout<<"L="<<start<<" j="<<j<<" R="<<end<<endl;
    print(data);
    // sort the rest 2 parts
    quick_sort(data,start,j);
    quick_sort(data,j+1,end);
}

int main(){
    int data[size];
    // create random data
    srand((unsigned int)time(NULL));rand();
    for(int i=0; i<size; i++)
        data[i]=rand()%1000;
    // print out original data
    cout<<"排序前"<<endl;
    print(data);
    // sort function call
    quick_sort(data,0,size);
    // print out final data
    cout<<"排序後"<<endl;
    print(data);
}