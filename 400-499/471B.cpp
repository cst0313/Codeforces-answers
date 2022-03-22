//471B
#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
ll templ,templ2,templ3;
int main(){
  int n;
  cin>>n;
  if(n<3){//can't have 3 configurations
      cout<<"NO";
      return 0;
  }
  if(n==3){//can have 3 configurations if only three are equal. I actually didn't need this but just in case
      cin>>templ>>templ2>>templ3;
      if(templ==templ2 and templ2==templ3){//actually don't need this but whatever
          cout<<"YES"<<endl;
          cout<<"1 2 3"<<endl;
          cout<<"1 3 2"<<endl;
          cout<<"2 3 1";
      }else{
          cout<<"NO";
      }
      return 0;
  }
  vector<pair<int,int> > v;//record number and position for final output
  for(ll i=0;i<n;i++){
      cin>>templ;
      v.pb(mp(templ,i+1));
  }
  sort(v.begin(),v.end());//sorting, of course since we have to output it in terms of increasing difficulty.
  vector<int>hi;
  bool flag=0;
  for(int i=0;i<n-1;i++){
      if(v[i].fi==v[i+1].fi){
          hi.pb(i);
          if(hi.size()==2){
              flag=1;//already fine, we can skip the scanning of the rest
          }
      }
      if(flag){//we found, speed up
          break;
      }
  }
  if(flag){
      cout<<"YES"<<endl;
      for(auto x:v){
          cout<<x.se<<" ";
      }
      cout<<endl;
      swap(v[hi[0]],v[hi[0]+1]);//note this trick: some might think there are two scenarios: one occuring >=3 times, or two occuring 2 times. however, this vector solves both these cases without complex implementation
      for(auto x:v){
          cout<<x.se<<" ";
      }
      cout<<endl;
      swap(v[hi[1]],v[hi[1]+1]);//doesn't matter if the number in hi[0] is equal to hi[1] anymore
      for(auto x:v){
          cout<<x.se<<" ";
      }
  }else{
      cout<<"NO"<<endl;
  }
  return 0;
}