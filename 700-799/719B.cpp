//719B.cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
  ll n;
  cin>>n;
  char a[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  bool flag=1;
  ll answer=10000000000000;
  ll p1=0;
  ll p2=0;
  for(ll i=0;i<n;i++){//brbrbrbrbrbrbr-
    if(flag){
      if(a[i]=='r'){
        p1++;
      }
    }else{
      if(a[i]=='b'){
        p2++;
      }
    }
    flag=!flag;
  }
  answer=min(answer,max(p1,p2));
  p1=0;
  p2=0;
  flag=0;
  for(ll i=0;i<n;i++){//rbrbrbrbr-
    if(flag){
      if(a[i]=='r'){
        p1++;
      }
    }else{
      if(a[i]=='b'){
        p2++;
      }
    }
    flag=!flag;
  }
  //Let's assume there are x misplaced 'b's and y misplaced 'r's. 
  //Overlap can /2 by swapping, additional is max(x,y)-min(x,y). Therefore minimum is overlap/2+remaining=max(x,y)
  
  answer=min(answer,max(p1,p2));
  cout<<answer<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll cases=1;
  //cin>>cases;
  while(cases--){
    solve();
  }
  return 0;
}