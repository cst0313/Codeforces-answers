//368B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n,m;
  cin>>n>>m;
  map<int,bool>b;
  int a[n];//this is the array of numbers, and array of distinct numbers (just wanted to save space)
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  b[a[n-1]]=1;//base, mark as read
  a[n-1]=1;//last one is always distinct
  for(ll i=n-2;i>=0;i--){//from back since the answer we want is from back
    if(b[a[i]]==0){//if not occured before
      b[a[i]]=1;//mark as occured
      a[i]=a[i+1]+1;//+1
    }else{
      a[i]=a[i+1];//copy
    }
  }
  for(ll i=0;i<m;i++){//follow the problem requirements
    cin>>n;
    cout<<a[n-1]<<endl;
  }
  return 0;
}