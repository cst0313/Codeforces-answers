//626B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool dp[201][201][201];
void s(ll rb,ll rg,ll rr){
  if(dp[rb][rg][rr]==1){
    return;
  }
  dp[rb][rg][rr]=1;
  if(rb>=2){
    s(rb-1,rg,rr);
  }
  if(rg>=2){
    s(rb,rg-1,rr);
  }
  if(rr>=2){
    s(rb,rg,rr-1);
  }
  if(rb>=1 and rg>=1){
    s(rb-1,rg-1,rr+1);
  }
  if(rb>=1 and rr>=1){
    s(rb-1,rg+1,rr-1);
  }
  if(rg>=1 and rr>=1){
    s(rb+1,rg-1,rr-1);
  }
  return;
}

int main(){
  ll n;
  cin>>n;
  string k;
  cin>>k;
  ll cb=0;
  ll cg=0;
  ll cr=0;
  for(char x:k){
    if(x=='B'){
      cb++;
    }else if(x=='G'){
      cg++;
    }else{
      cr++;
    }
  }
  s(cb,cg,cr);
  if(dp[1][0][0]){
    cout<<"B";
  }
  if(dp[0][1][0]){
    cout<<"G";
  }
  if(dp[0][0][1]){
    cout<<"R";
  }
  return 0;
}