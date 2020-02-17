#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define size 10
using namespace std;

void merge(int *data, int start, int end){
    int len=end-start;
    if(len<2) return; // no need to sort (too short)
    if(len==2){ // check and swap (only 2 elements)
        if(data[start]>data[start+1]){
            int temp=data[start];
            data[start]=data[start+1];
            data[start+1]=temp;
        }
        return; // sorted
    }
    // longer than 2
    int half=start+len/2; // split half
    for(int i=0; i<size; i++)
        cout<<setw(4)<<data[i];
    cout<<endl<<"L="<<start<<" M="<<half<<" R="<<end<<endl;
    // split to 2 parts
    merge(data,start,half);
    merge(data,half,end);
    // merge the 2 parts
    int temp[len];
    int p1=start, p2=half, pt=0; // p1 as pointer 1 , pt as pointer for temp
    bool lrb; // true means left, false means right (L / R Bar)
    while(pt<len){
        lrb=data[p1]<data[p2];
        if(p1==half) lrb=false;
        if(p2==end) lrb=true;
        temp[pt++]=data[ lrb?p1++:p2++ ];
        //if(lrb) p1++; else p2++;
    }
    for(int i=0; i<len; i++)
        data[start+i]=temp[i];
    return;
}

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
    // sort function call
    merge(data,0,size);
    // print out final data
    cout<<"排序後"<<endl;
    for(int i=0; i<size; i++)
        cout<<setw(4)<<data[i];
    cout<<endl;
}