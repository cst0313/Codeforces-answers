//368B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n,m;
  cin>>n>>m;
  map<int,bool>b;
  int a[n];
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  b[a[n-1]]=1;
  a[n-1]=1;
  for(ll i=n-2;i>=0;i--){
    if(b[a[i]]==0){
      b[a[i]]=1;
      a[i]=a[i+1]+1;
    }else{
      a[i]=a[i+1];
    }
  }
  for(ll i=0;i<m;i++){
    cin>>n;
    cout<<a[n-1]<<endl;
  }
  return 0;
}