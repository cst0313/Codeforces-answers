//466C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n;
  cin>>n;
  ll a[n];
  ll sum=0;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  if(sum%3!=0){
    cout<<0;
    return 0;
  }
  for(ll i=1;i<n;i++){
    a[i]+=a[i-1];//prefix sum trick
  }
  if(sum==0){//for this case, the sum of all numbers is zero, so the front and back will both be zero
    ll zerocount=0;
    for(ll i=0;i<n;i++){
      if(a[i]==0){
        zerocount++;
      }
    }
    zerocount--;//put two lines between the gaps of the zeroes to split sum
    cout<<max((ll)0,((zerocount-1)*zerocount)/2);
    return 0;
  }
  ll fcount=0;//found frontcut
  ll bcount=0;//found backcut
  string s="";
  //cout<<sum<<endl;
  for(ll i=0;i<n;i++){
    if(a[i]==sum/3){
      fcount++;
      s+="f";
    }else if(a[i]==2*sum/3){
      bcount++;
      s+="b";
    }
  }
  //cout<<s<<endl;
  ll answer=0;
  for(ll i=0;i<s.length();i++){
    if(s[i]=='f'){//now for every frontcut, we can choose from the backcut in the back
      fcount--;
      answer+=bcount;
    }else{
      bcount--;//we can't cut from here anymore, b<f.
      if(bcount==0){//no more backcuts, save time 
        break;
      }
    }
  }
  cout<<answer<<endl;
  return 0;
}
