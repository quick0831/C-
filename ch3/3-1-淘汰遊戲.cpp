#include <iostream>
#include <cstring>
using namespace std;

void next(int &seat, int max){
    seat++;
    if(seat>=max)
        seat=seat-max;
}

int main(){
    bool player[100];
    int n,p,remains,seat;
    while(cin>>n>>p){
        memset(player,false,100);
        remains=n;
        seat=0;
        while(remains!=1){
            for(int i=0;i<p;i++){
                next(seat,n);
                while(player[seat]){
                    next(seat,n);
                }
            }
            player[seat]=true;
            remains--;
            next(seat,n);
        }
        cout<<seat+1<<endl;
    }
}