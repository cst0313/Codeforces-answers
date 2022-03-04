//455A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int occ[100001];
int main(){
  ll n,tmp;
  cin>>n;
  ll m=-1;
  for(ll i=0;i<n;i++){
    cin>>tmp;
    occ[tmp]++;
    m=max(m,tmp);
  }
  ll dp[m+2][2];
  memset(dp,-1,sizeof(dp));
  dp[0][0]=0;
  dp[1][0]=0;
  dp[0][1]=0;
  dp[1][1]=occ[1];
  for(ll i=2;i<=m+1;i++){
    if(occ[i]!=0){
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
      dp[i][1]=max(dp[i-1][0]+i*(ll)occ[i],dp[i-2][1]);
    }else{
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
      dp[i][1]=dp[i][0];
    }
  }
  cout<<max(dp[m+1][0],dp[m+1][1]);
  return 0;
}