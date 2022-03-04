//455A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int occ[100001];//array for occurence
int main(){
  ll n,tmp;
  cin>>n;
  ll m=-1;
  for(ll i=0;i<n;i++){
    cin>>tmp;
    occ[tmp]++;//we could have done sorting and counting each number, but this is easier imho
    m=max(m,tmp);//find upper bound so we can conserve
  }
  ll dp[m+2][2];//two states: to include or not to include
  memset(dp,-1,sizeof(dp));//set 
  dp[0][0]=0;//no points
  dp[1][0]=0;//not including the ones
  dp[0][1]=0;//no zeroes
  dp[1][1]=occ[1];//points for including all ones
  for(ll i=2;i<=m+1;i++){
    if(occ[i]!=0){
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]);//don't include anything, copy max from prev
      dp[i][1]=max(dp[i-1][0]+i*(ll)occ[i],dp[i-2][1]);//current maximum is from not included previous, or maximum of past two included
    }else{
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]);//copy prev (actually code could be shorter but just doing this for cases)
      dp[i][1]=dp[i][0];//copy
    }
  }
  cout<<max(dp[m+1][0],dp[m+1][1]);//m doesn't work since it hasn't inherited max values from m-2. Extract maximum score
  return 0;
}