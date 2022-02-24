//257C.cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
const ld pi=acos(-1);
int main() {
  ll n;
  cin>>n;
  ld templ,templ2;
  vector<ld>v;//for the angles
  for(ll i=0;i<n;i++){
    cin>>templ>>templ2;
    if(templ>0 and templ2>0){//I
      v.pb(atan(templ2/templ));
    }else if(templ>0 and templ2<0){//IV
      v.pb(3*pi/2+atan(-1*templ/templ2));
    }else if(templ<0 and templ2>0){//II
      v.pb(pi/2+atan(-1*templ/templ2));
    }else if(templ<0 and templ2<0){//III
      v.pb(pi+atan(templ2/templ));
    }else if(templ==0){//can't divide by zero
      if(templ2>0){
        v.pb(pi/2);
      }else{
        v.pb(3*pi/2);
      }
    }else if(templ2==0){
      if(templ>0){
        v.pb(0);
      }else{
        v.pb(pi);
      }
    }
  }
  sort(v.begin(),v.end());
  ld ma=-1;
  for(ll i=0;i<v.size()-1;i++){
    ma=max(ma,v[i+1]-v[i]);
  }
  ma=max(ma,2*pi-v[v.size()-1]+v[0]);
  cout<<fixed<<setprecision(10)<<(2*pi-ma)*180/pi;
  return 0;
}