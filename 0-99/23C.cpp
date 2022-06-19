#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void solve(){
  ll n;
  cin>>n;
  ll templ,templ2;
  vector<pair<pair<ll,ll>,ll>>fruits;
  ll totalapples=0;
  for(ll i=0;i<2*n-1;i++){
    cin>>templ>>templ2;
    fruits.push_back(make_pair(make_pair(templ,templ2),i+1));//last one for keeping track of original position after sorting
    totalapples+=templ2;//find total apples
  }
  sort(fruits.begin(),fruits.end());//sort in terms of oranges. It is clear taking 1,3,...2n-1,2n-2 or 2,4,...2n-2 both satisfy the orange condition by inequalities
  ll a=0;//first case
  ll b=0;//second case
  for(ll i=0;i<2*n-2;i++){
    if(i%2==0){
      a+=fruits[i].first.second;
    }else{
      b+=fruits[i].first.second;
    }
  }
  a+=fruits[2*n-2].first.second;
  b+=fruits[2*n-2].first.second;
  cout<<"YES"<<endl;
  if(a>=ceil((double)totalapples/2)){//enough apples taking 2,4,...2n-2.
    for(ll i=0;i<2*n-1;i++){
      if(i%2==0){
        cout<<fruits[i].second<<" ";
      }
    }
    cout<<endl;
  }else{//or else we will have enough apples taking 1,3,...2n-3,2n-2. 
    //think carefully why this and the above is true
    for(ll i=0;i<2*n-1;i++){
      if(i%2==1){
        cout<<fruits[i].second<<" ";
      }
    }
    cout<<fruits[2*n-2].second<<endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);
  ll cases=1;
  cin>>cases;
  while(cases--){
    solve();
  }
  return 0;
}