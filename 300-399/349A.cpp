#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[2];//the number of 25 and 50 dollar bills remaining
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    int templ;
    for(int i=0;i<n;i++){
        cin>>templ;
        if(templ==25){
            a[0]++;//get a 25 bill
        }else if(templ==50){//get 50 bill, give 25 back
            a[0]--;
            a[1]++;
            if(a[0]<0){//oops, we couldn't give change
                cout<<"NO";
                return 0;
            }
        }else{//get 100. return 75 change
            if(a[1]>=1 and a[0]>=1){//50+25
                a[1]--;
                a[0]--;
            }else if(a[0]>=3){//or 25+25+25
                a[0]-=3;
            }else{//if both not possible, failed to give change
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";//no problems throughout phew
    return 0;
}