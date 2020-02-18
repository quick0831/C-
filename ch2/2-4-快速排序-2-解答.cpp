#include <iostream>
#include <ctime>
#include <cstdlib>
#define Size 10
using namespace std;
void swap(int *p,int *q){
    int tmp;
    tmp=*p;
    *p=*q;
    *q=tmp;
}
void printA(int *a,int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void quicksort(int *a,int L,int R){
    int i,j;
    if(L<R){
        i=L,j=R+1;
        while(1){
            while((i<R)&&(a[++i]<a[L]));
            while((j>0)&&(a[--j]>a[L]));
            if(i>=j) break;
            swap(&a[i],&a[j]);
        }
        swap(&a[L],&a[j]);
        cout<<"L="<<L<<" j="<<j<<" R="<<R<<endl;
        printA(a,Size);
        quicksort(a,L,j-1);
        quicksort(a,j+1,R);
    }
}
int main(){
    int A[Size];
    srand(time(NULL));
    for(int i=0;i<Size;i++){
        A[i]=rand()%1000+1;
    }
    cout<<"排序前"<<endl;
    printA(A,Size);
    quicksort(A,0,Size-1);
    cout<<"排序後"<<endl;
    printA(A,Size);
}