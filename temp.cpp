//270C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n;
  cin>>n;
  ll tld1=0;
  ld tld2=0;
  ll answer=0;
  for(ll i=0;i<n;i++){
    cin>>tld1>>tld2;
    if((ll)floor(tld2)==1){
      answer=max(answer,tld1+1);
    }else{
      answer=max(answer,tld1+(ll)ceil(log10(tld2)/log10(4)));
    }
  }
  cout<<answer;
  return 0;
}
