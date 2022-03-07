//408C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool issquare(ll x){
  if(floor(sqrt(x))*floor(sqrt(x))==x){
    return 1;
  }
  return 0;
}

int main(){
  bool go=0;
  ll x,y;
  cin>>x>>y;
  if(x>y){
    swap(x,y);
  }
  x=x*x;
  y=y*y;
  vector <pair<ll,ll>>v;
  vector <pair<ll,ll>>a;
  for(ll i=1;i<=floor(sqrt((ld)x));i++){
    if(i*i!=x and issquare(x-i*i)){
      ll g=floor(sqrt(x-i*i));
      v.push_back(make_pair(min(i,g),max(i,g)));
    }
  }
  for(auto x:v){
    for(ll i=1;i<=floor(sqrt((ld)y));i++){
      ll h1=x.first+i;
      ld w1=x.first*h1/(x.second);
      if(floor(w1)==w1 and w1*w1+h1*h1==y){
        go=1;
        a.push_back(make_pair(x.second,x.first));
        a.push_back(make_pair(-1*w1,h1));
        a.push_back(make_pair(0,0));
        break;
      }
      h1=x.second+i;
      w1=x.second*h1/(x.second);
      if(floor(w1)==w1 and w1*w1+h1*h1==y){
        go=1;
        a.push_back(make_pair(x.first,x.second));
        a.push_back(make_pair(-1*w1,h1));
        a.push_back(make_pair(0,0));
        break;
      }
    }
    if(go){
      break;
    }
  }
  if(go){
    cout<<"YES"<<endl;
    cout<<a[0].first<<" "<<a[0].second<<endl;
    cout<<a[1].first<<" "<<a[1].second<<endl;
    cout<<a[2].first<<" "<<a[2].second<<endl;
  }else{
    cout<<"NO";
  }
  return 0;
}
