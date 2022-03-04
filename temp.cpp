//706C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXLL=numeric_limits<ll>::max();

int main(){
  string temps,temps2,temps3,temps4;
  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll dp[n+1][2];
  for(ll i=0;i<n+1;i++){
    dp[i][0]=MAXLL;
    dp[i][1]=MAXLL;
  }
  cin>>temps2;
  temps=temps2;
  dp[0][0]=0;//don't
  dp[0][1]=a[0];//reverse first
  reverse(temps2.begin(),temps2.end());
  for(ll i=1;i<n;i++){
    cin>>temps4;
    temps3=temps4;
    reverse(temps4.begin(),temps4.end());
    if(temps<=temps3 and dp[i-1][0]!=MAXLL){
      dp[i][0]=min(dp[i-1][0],dp[i][0]);//nothing wrong
    }
    if(temps<=temps4 and dp[i-1][0]!=MAXLL){
      dp[i][1]=min(dp[i-1][0]+a[i],dp[i][1]);//need cost of reversing current string
    }
    if(temps2<=temps3 and dp[i-1][1]!=MAXLL){
      dp[i][0]=min(dp[i-1][1],dp[i][0]);//nothing wrong
    }
    if(temps2<=temps4 and dp[i-1][1]!=MAXLL){
      dp[i][1]=min(dp[i-1][1]+a[i],dp[i][1]);//need cost of reversing current string
    }
    temps=temps3;
    temps2=temps4;
  }
  if(dp[n-1][0]==MAXLL and dp[n-1][1]==MAXLL){
    cout<<-1;
  }else{
    cout<<min(dp[n-1][0],dp[n-1][1]);
  }
  return 0;
}