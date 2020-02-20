#include <iostream>
#include <algorithm>
using namespace std;

struct segment{
    int a,b;
};
segment seg[10000];

bool cmp(segment a,segment b){
    return (a.a!=b.a)?(a.a<b.a):(a.b<b.b);
}

int main(){
    unsigned int n,i,len;
    segment k;
    while(cin>>n){
        len=0;
        for(i=0;i<n;i++)
            //cin>>seg[i].a>>seg[i].b;
            scanf("%d %d", &seg[i].a, &seg[i].b);
        sort(seg,seg+n,cmp);
        k=seg[0];
        for(i=1;i<n;i++){
            if(seg[i].a<=k.b)
                k.b=max(seg[i].b,k.b);
            else{
                len=len+k.b-k.a;
                k=seg[i];
            }
        }
        len=len+k.b-k.a;
        cout<<len<<endl;
    }
}