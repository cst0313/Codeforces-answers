//131B.cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
  ll n;
  cin>>n;
  ll templ;
  map<ll,ll>m;
  for(ll i=0;i<n;i++){
    cin>>templ;
    m[templ]++;
  }
  ll answer=0;
  for(ll i=1;i<=10;i++){
    answer+=m[i]*m[-i];
  }
  answer+=(m[0]*(m[0]-1))/2;
  cout<<answer<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll cases=1;
  //cin>>cases;
  while(cases--){
    solve();
  }
  return 0;
}