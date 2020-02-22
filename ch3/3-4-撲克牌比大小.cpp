#include <iostream>
#include <algorithm>
using namespace std;

struct card{
    int n; // card number (AKQJT98765432) (A=14,T=10) (A>K)
    int t; // card type (1=C,2=D,3=H,4=S) (club,Diamond,Heart,Spade)
};

void get(card &k){
    char input[3];
    cin>>input;
    switch(input[1]){
        case 'A': k.n=14; break;
        case 'K': k.n=13; break;
        case 'Q': k.n=12; break;
        case 'J': k.n=11; break;
        case 'T': k.n=10; break;
        case '9': k.n=9; break;
        case '8': k.n=8; break;
        case '7': k.n=7; break;
        case '6': k.n=6; break;
        case '5': k.n=5; break;
        case '4': k.n=4; break;
        case '3': k.n=3; break;
        case '2': k.n=2; break;
        default: k.n=1;
    }
    switch(input[0]){
        case 'C': k.t=1; break;
        case 'D': k.t=2; break;
        case 'H': k.t=3; break;
        case 'S': k.t=4; break;
        default: k.t=0;
    }
}

bool cmp(card &a, card &b){
    return (a.n==b.n)?(a.t>b.t):(a.n>b.n);
}

struct type{
    int w; // the card combination type (win type)
    int n; // the number of the set
};

type analyze(card *a){
    int i;
    type ans;
    // check if number is decreasing (all five cards)
    bool number_decrease=true;
    for(i=1;i<5;i++)
        number_decrease=number_decrease && (a[i-1].n==(a[i].n-1));
    // check if set has same card type (all five cards)
    bool same_card_type=true;
    cout<<a[0].t<<" ";
    for(i=1;i<5;i++)
        same_card_type=same_card_type && (a[0].t==a[i].t);
    cout<<endl;
    ans.n=a[0].n;
    if(number_decrease)
        if(same_card_type)
            ans.w=9;
        else
            ans.w=5;
    else
        if(same_card_type)
            ans.w=6;
        else{ // following checks for other set possiblity
            bool b;
            int j,k;
            // check for same number in a set
            for(i=4;i>=2;i--){ // check if the i cards have same number
                for(j=0;j<=(5-i);j++){ // run throug j possibilities
                    b=true;
                    for(k=1;k<i;k++)
                        if(a[j].n!=a[j+k].n)
                            b=false;
                    if(b)
                        break;
                }
                if(b)
                    break;
            }
            if(b){
                ans.n=a[j].n;
                if(i==4){
                    ans.w=8;
                }else if(i==3){
                    // still have more to check (type 4,7)
                    if(j==0){ // aaabc
                        if(a[3].n==a[4].n)
                            ans.w=7;
                        else
                            ans.w=4;
                    }else if(j==1){ // abbbc
                        ans.w=4;
                    }else{ // j==2 abccc
                        if(a[0].n==a[1].n)
                            ans.w=7;
                        else
                            ans.w=4;
                    }
                }else{ // i==2
                    // still have more to check (type 2,3)
                    if(j==0){ // aabcd
                        if(a[2].n==a[3].n || a[3].n==a[4].n)
                            ans.w=3;
                        else
                            ans.w=2;                        
                    }else if(j==1){ // abbcd
                        if(a[3].n==a[4].n)
                            ans.w=3;
                        else
                            ans.w=2;                        
                    }else{ // abccd or abcdd
                        ans.w=2;
                    }
                }
            }else{
                ans.w=1;
                ans.n=a[0].n;
            }
        }
    return ans;
}

int main(){
    card a[5],b[5];
    while(true){
        for(int i=0;i<5;i++)
            get(a[i]);
        for(int i=0;i<5;i++)
            get(b[i]);
        sort(a,a+5,cmp);
        sort(b,b+5,cmp);
        type aw=analyze(a);
        type bw=analyze(b);
        if(aw.w==bw.w){
            if(aw.n==bw.n)
                cout<<"平手"<<endl;
            else if(aw.n>bw.n)
                cout<<"第一位玩家獲勝"<<endl;
            else
                cout<<"第二位玩家獲勝"<<endl;
        }else if(aw.w>bw.w)
            cout<<"第一位玩家獲勝"<<endl;
        else
            cout<<"第二位玩家獲勝"<<endl;
    }
}