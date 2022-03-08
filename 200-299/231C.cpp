//231C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n,k;
  cin>>n>>k;
  ll templ;
  vector<ll>v;
  for(ll i=0;i<n;i++){
    cin>>templ;
    v.push_back(templ);
  }
  sort(v.begin(),v.end());
  ll ans=0,ele=-1,j=0,prev=0;//two pointer
  ll total=0;
  for(ll i=0;i<n;i++){
    if(i>0 and v[i]!=v[i-1]){//move the total up with multiplication
      total+=prev*(v[i]-v[i-1]);//different element with difference
    }
    while(total>k and j<=i){//out of our power, need to reduce
      total-=(v[i]-v[j]);//shift one less
      j++;
    }
    prev=i-j+1;//num elements
    if(ans<prev){//we have a new high score!~
      ans=prev;
      ele=v[i];
    }
  }
  cout<<ans<<" "<<ele;
  return 0;
}
