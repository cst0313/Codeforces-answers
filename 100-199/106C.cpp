//106C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
//I originally decided to make a dp array dp[1000][100][100]...[100] lol don't do it, will get CE
int main(){
  int n,m;
  cin>>n>>m;
  int cz,dz;//c0,d0 which are the costs and money earned from making pure dough
  cin>>cz>>dz;
  int a[m];//stuffing left 
  int b[m];//takes stuffing
  int c[m];//takes dough
  int d[m];//money return
  for(ll i=0;i<m;i++){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  }
  int dp[n+1][m+1];//we want to use n dough and m stuff
  memset(dp,0,sizeof(dp));
  for(int i=0;i<=floor((ld)n/cz);i++){//all dough
    dp[i*cz][0]=dz*i;
  }
  int answer=-1;
  for(int i=1;i<=m;i++){//for using only ingredients 1 up to i
    for(int j=0;j<=n;j++){//and using n dough
      for(int k=0;k<=min((int)floor((double)a[i-1]/b[i-1]),(int)floor((double)j/c[i-1]));k++){
        //first constraint: no stuffing left. Second constraint: no dough left
        dp[j][i]=max(dp[j][i],dp[j-c[i-1]*k][i-1]+d[i-1]*k);//we choose to make k buns of ingredient i, so we use dough c[i-1]*k, and we earn d[i-1]*k.
        answer=max(answer,dp[j][i]);//answer is maximum of all configurations
      }
    }
  }
  cout<<answer;
  return 0;
}
