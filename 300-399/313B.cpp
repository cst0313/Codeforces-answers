//313B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  string s;
  cin>>s;
  ll num[s.length()];
  num[0]=0;
  for(ll i=1;i<s.length();i++){
    if(s[i]==s[i-1]){
      num[i]=num[i-1]+1;
    }else{
      num[i]=num[i-1];
    }
  }
  ll q;
  cin>>q;
  ll t,b;
  while(q--){
    cin>>t>>b;
    cout<<num[b-1]-num[t-1]<<endl;
  }
  return 0;
}