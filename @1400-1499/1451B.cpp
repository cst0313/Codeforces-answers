//1451B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    string s;
    bool flag=0;//indicate got a good substr
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        cin>>s;
        ll l,r;
        //idea of the problem: look on the left for the leftmost character of the substring, and look on the right for the rightmost character of the substring.
        //if there is a match, then there is a good substring
        for(ll j=0;j<b;j++){
            flag=0;
            cin>>l>>r;
            for(ll k=0;k<l-1;k++){
                if(s[k]==s[l-1]){//up to l
                    flag=1;
                    break;
                }
            }
            for(ll k=r;k<a;k++){
                if(s[k]==s[r-1]){//from r-1
                    flag=1;
                    break;
                }
            }
            if(flag){//we have a good substr
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
  return 0;
}