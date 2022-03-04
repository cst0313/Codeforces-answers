//706C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXLL=numeric_limits<ll>::max();

int main(){
  string temps,temps2,temps3,temps4;//actually we can use something like vector<string> or deque. I just chose to use 4 strings :D
  ll n;
  cin>>n;
  ll a[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll dp[n+1][2];//we have two actions, reverse string or no
  for(ll i=0;i<n+1;i++){//memset only works with 0 and -1! so set with loop
    dp[i][0]=MAXLL;
    dp[i][1]=MAXLL;
  }
  cin>>temps2;//reversed string
  temps=temps2;//normal string
  dp[0][0]=0;//don't reverse first string
  dp[0][1]=a[0];//reverse first
  reverse(temps2.begin(),temps2.end());//well now it's official
  for(ll i=1;i<n;i++){
    cin>>temps4;//input second reversed string
    temps3=temps4;//second normal string
    reverse(temps4.begin(),temps4.end());//officially reversed
    if(temps<=temps3 and dp[i-1][0]!=MAXLL){//not previously unavailable, lexicographically smaller
      dp[i][0]=min(dp[i-1][0],dp[i][0]);//nothing wrong, continue
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
    temps=temps3;//shift current string to become previous 
    temps2=temps4;
  }
  if(dp[n-1][0]==MAXLL and dp[n-1][1]==MAXLL){//oops both not available
    cout<<-1;//no way to get conditions
  }else{
    cout<<min(dp[n-1][0],dp[n-1][1]);//minimum cost
  }
  return 0;
}