#include <iostream>
#include <ctime>
#include <cstdlib>
#define Size 10
using namespace std;
void merge(int *,int,int,int);
void mergesort(int *,int,int);
void printA(int *a,int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void mergesort(int *a,int L,int R){
    int M;
    if(L<R){
        M=(L+R)/2;
        mergesort(a,L,M);
        mergesort(a,M+1,R);
        merge(a,L,M,R);
        cout<<"L="<<L<<" M="<<M<<" R="<<R<<endl;
        printA(a,Size);
    }
}
void merge(int *a,int L,int M,int R){
    int left,right,i,tmp[Size];
    left=L;
    right=M+1;
    i=L;
    while((left<=M)&&(right<=R)){
        if(a[left]<a[right]){
            tmp[i]=a[left];
            i++;left++;
        }else{
            tmp[i]=a[right];
            i++;right++;
        }
    }
    while(left<=M){
        tmp[i]=a[left];
        i++;left++;
    }
    while(right<=R){
        tmp[i]=a[right];
        i++;right++;
    }
    for(i=L;i<=R;i++){
        a[i]=tmp[i];
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
    mergesort(A,0,Size-1);
    cout<<"排序後"<<endl;
    printA(A,Size);
}