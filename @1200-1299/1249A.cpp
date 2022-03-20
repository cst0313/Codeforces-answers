//1249A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){//key observation is we can divide them for all odd numbers into one team, and even numbers into another, so the maximum number of teams is 2
    ll t,n,templ;
    cin>>t;
    int a[101];//check the limit, since all numbers are distinct and have a limit of up to 100
    bool flag=0;
    for(ll i=0;i<t;i++){
        memset(a,0,sizeof(a));//remember to reset after every testcase
        cin>>n;
        flag=0;//indicate a clash-> the need for two teams
        for(ll j=0;j<n;j++){
            cin>>templ;
            a[templ]=1;
            if(a[templ-1]==1 or a[templ+1]==1){//check if violated
                flag=1;
            }
        }
        cout<<flag+1<<endl;//shortcut for 1 or 2 teams
    }
    return 0;
}