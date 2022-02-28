//118D
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define mod 100000000
ll f,h,mfs,mhs;
ll memo[101][101][11][11];
ll dp(ll frem,ll hrem,ll fadd,ll hadd){//remaining troops and we can add before breaking the maximum streak
  if(frem+hrem==0){
    return 1;
  }
  if(memo[frem][hrem][fadd][hadd]==-1){
    ll answer=0;
    if(frem>0 and fadd>0){
      answer=(answer+dp(frem-1,hrem,fadd-1,mhs))%mod;
    }
    if(hrem>0 and hadd>0){
      answer=(answer+dp(frem,hrem-1,mfs,hadd-1))%mod;
    }
    memo[frem][hrem][fadd][hadd]=answer%mod;
  }
  return memo[frem][hrem][fadd][hadd];
}
int main(){
  cin>>f>>h>>mfs>>mhs;
  memset(memo,-1,sizeof(memo));
  cout<<dp(f,h,mfs,mhs)%mod;
  return 0;
}