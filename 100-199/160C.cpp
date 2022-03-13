//160C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n,k;
  cin>>n>>k;
  ll a[n];
  map<ll,ll>m;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    m[a[i]]++;
  }
  sort(a,a+n);
  ll cur=0;
  for(auto x:m){
    if(cur+x.second*n>=k){
      cout<<x.first<<" ";
      cur=k-cur;
      if(x.second==1){
        cout<<a[cur-1];
      }else{
        cout<<a[(ll)ceil((ld)cur/x.second)-1];
      }
      return 0;
    }
    cur+=x.second*n;
  }
  return 0;
}
