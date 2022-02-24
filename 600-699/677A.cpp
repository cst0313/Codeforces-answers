//677A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
  ll n,h;
  cin>>n>>h;
  ll templ;
  ll ans=0;
  for(ll i=0;i<n;i++){
    cin>>templ;
    if(templ>h){
      ans+=2;
    }else{
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}