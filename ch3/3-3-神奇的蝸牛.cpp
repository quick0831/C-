#include <iostream>
using namespace std;

int main(){
    float h,d,n;
    while(cin>>h>>d>>n){
        int day=0;
        float height=0;
        while(true){
            // day time
            height=height+d;
            if(height>=h){
                cout<<"第 "<<day+1<<" 天爬到樹頂"<<endl;
                break;
            }
            // night time
            height=height-n*(1+0.1*day);
            if(height<=0){
                cout<<"第 "<<day+1<<" 天掉到地面"<<endl;
                break;
            }
            // end of day
            day++;
        }
    }
}