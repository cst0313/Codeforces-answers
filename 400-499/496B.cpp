//496B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){ 
    string a[10];//all shifts, we don't want to add every single time
    ll n;
    cin>>n;
    cin>>a[0];
    for(ll i=1;i<10;i++){
        string temps="";
        for(ll j=0;j<n;j++){
            if(a[i-1][j]=='9'){//exception as stated in problem statement
                temps+='0';
            }else{
                temps+=a[i-1][j]+1;//increment this number
            }
        }
        a[i]=temps;//remember to set it
    }
    string answer="";
    answer.append(n+1,'9');//just a maximum string possible
    for(ll i=0;i<n;i++){//for each possible index to start
        int dist=(10-(a[0][i]-'0'))%10;//times needed to add, which is stored in the array a
        answer=min(a[dist].substr(i,n-i)+a[dist].substr(0,i),answer);//implement minimum
    }
    cout<<answer;
    return 0;
}
