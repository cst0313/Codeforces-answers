//454B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
ll answer=-1;
int main(){
  ll n;
  cin>>n;
  ll a[n];
  int drop=0;
  ll r=0;
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  ll base=a[0];
  ll prev=a[0];
  for(ll i=1;i<n;i++){
    if(a[i]<prev){
      drop++;
      if(drop>=2){
        cout<<-1;
        return 0;
      }
      if(drop==1 and a[i]>base){
        cout<<-1;
        return 0;
      }
      r=i;
    }else{
      if(drop==1 and a[i]>base){
        cout<<-1;
        return 0;
      }
    }
    prev=a[i];
  }
  if(drop==0){
    cout<<0;
  }else{
    cout<<n-r;
  }
  return 0;
}