#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

struct student{
    int chinese;
    int english;
    int math;
};

bool cmp(student a, student b){
    if(a.chinese>b.chinese) return true;
    if(a.chinese<b.chinese) return false;
    if(a.english>b.english) return true;
    if(a.english<b.english) return false;
    if(a.math>b.math) return true;
    if(a.math<b.math) return false;
    return true;
}

int main(){
    const int count=40;
    student stu[count];
    srand(time(NULL));
    for(int i=0;i<count;i++){
        stu[i].chinese=rand()%40+60;
        stu[i].english=rand()%40+60;
        stu[i].math=rand()%40+60;
    }
    sort(stu,stu+count,cmp);
    for(int i=0;i<count;i++){
        cout<<stu[i].chinese<<" "<<stu[i].english<<" "<<stu[i].math<<endl;
    }
}