#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
ll templ,templ2,templ3;
int main(){
  ll n;
  cin>>n;
  for(ll i=0;i<n;i++){
      ll a,b,x,y;
      cin>>a>>b>>x>>y;
      ll ar[a+1];
      ar[0]=0;
      templ=0;
      for(ll j=1;j<=a;j++){
          if(ar[j-1]+x<=b){
              ar[j]=ar[j-1]+x;
          }else{
              ar[j]=ar[j-1]-y;
          }
      }
      for(ll j=0;j<=a;j++){
          templ+=ar[j];
      }
      cout<<templ<<endl;
  }
  return 0;
}
