//626B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool dp[201][201][201];//memo array
void s(ll rb,ll rg,ll rr){//remaining blue, green, red
  if(dp[rb][rg][rr]==1){//we already went down that path, no need to go again
    return;
  }
  dp[rb][rg][rr]=1;//visited <-> achievable configuration
  if(rb>=2){//2nd way of combining: BB->B
    s(rb-1,rg,rr);
  }
  if(rg>=2){//GG->G
    s(rb,rg-1,rr);
  }
  if(rr>=2){//RR->R
    s(rb,rg,rr-1);
  }
  if(rb>=1 and rg>=1){//BG->R
    s(rb-1,rg-1,rr+1);
  }
  if(rb>=1 and rr>=1){//BR->G
    s(rb-1,rg+1,rr-1);
  }
  if(rg>=1 and rr>=1){//GR->B
    s(rb+1,rg-1,rr-1);
  }
  return;
}

int main(){
  ll n;
  cin>>n;//actually quite useless? We can do cin>>char though
  string k;
  cin>>k;
  ll cb=0;//count of B
  ll cg=0;//count of G
  ll cr=0;//count of R
  for(char x:k){
    if(x=='B'){
      cb++;
    }else if(x=='G'){
      cg++;
    }else{
      cr++;
    }
  }
  s(cb,cg,cr);//do it
  if(dp[1][0][0]){//1B remaining
    cout<<"B";
  }
  if(dp[0][1][0]){//1G remaining 
    cout<<"G";
  }
  if(dp[0][0][1]){//1R remaining
    cout<<"R";
  }
  return 0;
}