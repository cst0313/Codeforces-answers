//141C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  vector <pair<int,string>>v;
  ll n;
  cin>>n;
  string temps;
  int templ;
  map<int,int>m;
  for(ll i=0;i<n;i++){
    cin>>temps>>templ;
    m[templ]++;
    v.push_back(make_pair(templ,temps));
  }
  sort(v.begin(),v.end());//sort the students according to the people in front that are taller than them
  vector <int> vs;
  for(int i=0;i<n;i++){
    if(v[i].first>i){//greedy, but still not possible
      cout<<-1;
      return 0;
    }
    vs.insert(vs.begin()+v[i].first,i);
  }
  int ans[n];
  for(ll i=0;i<n;i++){//answer position is n-i
    ans[vs[i]]=n-i;
  }
  for(ll i=0;i<n;i++){
    cout<<v[i].second<<" "<<ans[i]<<endl;
  }
  return 0;
}
