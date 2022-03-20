//980A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;
    ll d=0;//number of dashes/strings
    ll o=0;//number of pearls
    for(ll i=0;i<s.length();i++){//don't have to care about the order, so just count # of elements
        if(s[i]=='-'){
            d+=1;
        }else{
            o+=1;
        }
    }
    if(d==0 or o==0){//got runtime error for o==0, so handle here
        cout<<"YES";
        return 0;
    }
    if(o>d){//apparently
        cout<<"NO";
        return 0;
    }
    if(d%o==0){//in a cycle, the number of strings must be a multiple of the number of pearls to satisfy the condition stated
        cout<<"YES";    
    }else{
        cout<<"NO";
    }
  return 0;
}