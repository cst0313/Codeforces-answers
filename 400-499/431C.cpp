//431C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define mod 1000000007
ll m[202];
ll dp(ll sum,ll av){//sum, available additions; actually is the famous coin change problem
  memset(m,0,sizeof(m));
  m[0]=1;
  for(ll i=0;i<sum;i++){//don't have to = sum since +1>sum in j loop
    for(ll j=1;j<=av;j++){//for all available values
      m[i+j]=(m[i+j]+m[i])%mod;//could have written this better with less memory but whatever
    }
  }
  return m[sum];
}
int main(){
  ll n,k,d;
  cin>>n>>k>>d;
  cout<<(dp(n,k)-dp(n,d-1)+mod)%mod;//+mod % mod trick, and this -dp(n,d-1) is since we don't want any solution that uses only the first d-1 numbers; remember we want at least one number >=d
  return 0;
}