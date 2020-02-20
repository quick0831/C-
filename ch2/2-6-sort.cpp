/*

#include <algorithm>
sort(first, last)
sort(first, last, cmp)
stable_sort(first, last)
stable_sort(first, last, cmp)

*/

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#define Size 10
using namespace std;
bool cmp1(int i,int j){
    return (i<j);
}
bool cmp2(int i,int j){
    return (i>j);
}
void printA(int *a,int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int A[Size];
    srand(time(NULL));
    for(int i=0;i<Size;i++){
        A[i]=rand()%1000+1;
    }
    cout<<"排序前"<<endl;
    printA(A,Size);
    sort(A,A+Size);
    cout<<"使用sort(A,A+Size)排序後"<<endl;
    printA(A,Size);
    for(int i=0;i<Size;i++){
        A[i]=rand()%1000+1;
    }
    cout<<"排序前"<<endl;
    printA(A,Size);
    sort(A,A+Size,cmp1);
    cout<<"使用sort(A,A+Size,cmp1)排序後"<<endl;
    printA(A,Size);
    for(int i=0;i<Size;i++){
        A[i]=rand()%1000+1;
    }
    cout<<"排序前"<<endl;
    printA(A,Size);
    sort(A,A+Size,cmp2);
    cout<<"使用sort(A,A+Size,cmp2)排序後"<<endl;
    printA(A,Size);
}