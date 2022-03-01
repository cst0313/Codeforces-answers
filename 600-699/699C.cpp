//699C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[101][3];//3 actions: do nothing, go to the gym, or compete
//the dp will record how many days we can do stuff
int main(){
  ll n;
  cin>>n;
  ll templ;
  for(ll i=1;i<=n;i++){
    cin>>templ;
    dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);//do nothing, copy from previous day
    if(templ==1){//contest open
      dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;//we can go compete, +1 day did stuff. Since we can't go compete two days in a row, we only fetch maximum of yesterday doing nothing or going to a gym.
    }else if(templ==2){//gym open
      dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;//we can go to the gym
    }else if(templ==3){//both open
      dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;//we can go compete
      dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;//we can go to the gym
    }
  }
  cout<<n-max(max(dp[n][0],dp[n][1]),dp[n][2]);//n-, since we want to find the minimum number of days resting
  return 0;
}