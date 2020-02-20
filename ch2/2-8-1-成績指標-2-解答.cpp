#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a,int b){
    return a<b;
}
int main(){
    int n,score[20],a60,b60;
    while(cin>>n){
        a60=-1,b60=-1;
        for(int i=0;i<n;i++){
            cin>>score[i];
        }
        sort(score,score+n,cmp);
        for(int i=0;i<n;i++){
            if(score[i]<60) b60=score[i];
        }
        for(int i=n-1;i>=0;i--){
            if(score[i]>=60) a60=score[i];
        }
        cout<<score[0];
        for(int i=1;i<n;i++){
            cout<<" "<<score[i];
        }
        cout<<endl;
        if(b60!=-1)cout<<b60<<endl;
        else cout<<"best case"<<endl;
        if(a60!=-1)cout<<a60<<endl;
        else cout<<"worst case"<<endl;
    }
}