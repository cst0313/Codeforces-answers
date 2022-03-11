//270C
//To be honest, I think this one is a bit too easy for a C.
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n;
  cin>>n;
  ll tld1=0;
  ld tld2=0;//for the log, could use long long then convert to long double afterwards.
  ll answer=0;
  for(ll i=0;i<n;i++){//here, note that the boxes are independent of each other, so we just find maximum for each size
    cin>>tld1>>tld2;
    if((ll)floor(tld2)==1){//log10(1)=0, aware
      answer=max(answer,tld1+1);
    }else{//the side we need, is original side+ log_4_number of boxes.
      answer=max(answer,tld1+(ll)ceil(log10(tld2)/log10(4)));
    }
  }
  cout<<answer;//take maximum
  return 0;
}
