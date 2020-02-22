#include <iostream>
using namespace std;

int main(){
    int t,n;
    while(cin>>t>>n){
        int time=t*60;
        // t will be overwirtten later
        t=0;
        int in; // when the customer comes in
        int r; // required time to serve
        int idle=0; // when the clerk has no customer
        for(int i=0;i<n;i++){
            cin>>in>>r;
            if(t<time){
                if(in>=t){
                    idle=idle+in-t;
                    t=in+r;
                }else{
                    t=t+r;
                }
            }
        }
        if(t<time) idle=idle+time-t;
        cout<<idle<<endl;
    }
}