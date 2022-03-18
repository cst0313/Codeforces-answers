//381C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
  ll n,typ,t1,t2;
  ll pos=1;
  map<ll,ll>m;//how much we jump
  map<ll,ll>save;//numbers 
  cin>>n;
  ll front=-1;
  ll cumu=0;
  for(ll i=0;i<n;i++){
    cin>>typ;
    if(typ==1){
      cin>>t1;
      save[pos]=t1;
      pos++;
    }else{
      cin>>t2>>t1;//t2 is length of prefix, t1 is the times we add
      if(t1==1 and t2==1){
        save[pos]=save[1];
        pos++;
        continue;
      }
      cumu-=m[pos];
      m[pos]=-cumu-pos+1;
      cumu+=m[pos];
      for(ll j=0;j<t1-1;j++){
        pos+=t2;
        m[pos]-=t2;
        cumu-=t2;
      }
      pos+=t2;
      m[pos]-=cumu;//we want this to be zero
      cumu+=m[pos];
    }
    /*for(ll k=1;k<=pos;k++){
      cout<<m[k]<<" ";
    }
    cout<<endl;*/
  }
  for(ll i=1;i<pos;i++){
    m[i]+=m[i-1];
    //cout<<m[i]<<" ";
  }
  //cout<<endl;
  ll cur;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>cur;
    while(m[cur]<0){
      cur+=m[cur];
      //cout<<cur<<endl;
    }
    cout<<save[cur]<<" ";
  }
  return 0;
}
