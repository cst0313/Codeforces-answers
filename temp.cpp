//699C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[101][3];
int main(){
  ll n;
  cin>>n;
  ll templ;
  for(ll i=1;i<=n;i++){
    cin>>templ;
    dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
    if(templ==1){
      dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
    }else if(templ==2){
      dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
    }else if(templ==3){
      dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
      dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
    }
  }
  cout<<n-max(max(dp[n][0],dp[n][1]),dp[n][2]);
  return 0;
}