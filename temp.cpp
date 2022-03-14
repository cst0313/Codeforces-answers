//106C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  int n,m;
  cin>>n>>m;
  int cz,dz;
  cin>>cz>>dz;
  int a[m];//stuffing left 
  int b[m];//takes stuffing
  int c[m];//takes dough
  int d[m];//money return
  for(ll i=0;i<m;i++){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  }
  int dp[n+1][m+1];
  memset(dp,0,sizeof(dp));
  for(int i=0;i<=floor((ld)n/cz);i++){
    dp[i*cz][0]=dz*i;
  }
  int answer=-1;
  for(int i=1;i<=m;i++){
    for(int j=0;j<=n;j++){
      for(int k=0;k<=min((int)floor((double)a[i-1]/b[i-1]),(int)floor((double)j/c[i-1]));k++){
        //cout<<"K: "<<k<<" j: "<<j<<" i:  "<<i<<endl;
        dp[j][i]=max(dp[j][i],dp[j-c[i-1]*k][i-1]+d[i-1]*k);
        answer=max(answer,dp[j][i]);
      }
    }
  }
  /*
  cout<<endl;
  for(int i=0;i<=n;i++){
    for(int j=0;j<m+1;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  cout<<answer;
  return 0;
}
