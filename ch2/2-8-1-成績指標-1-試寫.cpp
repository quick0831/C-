#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int count;
    cin>>count;
    int stu[count];
    for(int i=0;i<count;i++)
        cin>>stu[i];
    sort(stu,stu+count);
    for(int i=0;i<count-1;i++)
        cout<<stu[i]<<" ";
    cout<<stu[count-1]<<endl;
    if(stu[0]>=60){
        cout<<"best case"<<endl;
        cout<<stu[0]<<endl;
    }else if(stu[count-1]<60){
        cout<<stu[count-1]<<endl;
        cout<<"worst case"<<endl;
    }else{
        int i=0;
        while(stu[++i]<60);
        cout<<stu[i-1]<<endl;
        cout<<stu[i]<<endl;
    }
}