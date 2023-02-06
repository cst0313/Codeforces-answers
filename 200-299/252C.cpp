//252C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n,d;
  cin>>n>>d;
  ll answer = 0;
  vector<ll>v;
  ll templ,pt1,pt2;//two pointer approach
  for(ll i=0;i<n;i++){
    cin>>templ;
    v.push_back(templ);
  }
  //vector of all numbers
  pt1 = v[0];
  ll pos1 = 0;
  ll pos2 = 1;
  pt2 = v[pos2];
  while(pos1 != n-1){//while first pointer not reached end
    if(pt2-pt1<=d){//satisfy conditions
      answer += max((ll)0,(pos2 - pos1 - 1)*(pos2 - pos1 -2)/2);//math combinatorics, number of combinations ending with pt2 but not being counted before
      pos2++;//increase difference
      if(pos2 >= n){//if ending pointer reached end, break since if we continue we recount those from increment of pt1
        break;
      }
    }else{
      pos1++;//reduce difference
    }
    pt1 = v[pos1];//update pointers
    pt2 = v[pos2];
  }
  cout<<answer;
  return 0;
} 
