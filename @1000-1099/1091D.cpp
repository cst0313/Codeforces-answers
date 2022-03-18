//1091D
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=998244353;
int main(){
  ll n;
  cin>>n;
  if(n==1){
    cout<<1;
    return 0;
  }
  ll fa[n+1];
  fa[n]=n;
  for(ll i=n-1;i>=1;i--){
    fa[i]=(fa[i+1]*i)%mod;
  }
  ll answer=(fa[1]*n)%mod;
  for(ll i=n;i>=2;i--){
    answer-=fa[i];
  }
  cout<<(answer%mod+mod)%mod;
  return 0;
}
  /*We know the number of subarrays possible is n*n!-(n-1), since
    to sum up to n*(n+1)/2, we must have a full "collection" 
    of 1 to n, and the last n-1 digits can't be chosen as a starting
    index. Instead of producing each possible substring, and 
    counting (which will clearly get Time Limit Exceeded 
    (TLE)), we should remove the "invalid" substrings
    that don't sum to n*(n+1)/2. Examining each starting 
    index modulo n, i.e. 0,1,...n-1, we find out the number of
    invalid substrings with index k modulo n is nPk-1. This 
    pattern is found through listing examples. 
    
    Substring transitions: 
    If we move from 12(k)(k-1)...1 to 13(2)...(k), we have an
    invalid substring at remainder 2, since there are two 
    copies of 1. Same happens for 13..->14->...->1k->21->
    ...->2k->...->k(k-1). We notice, that there are nP2 
    numbers with 2 digit indexes, and nP2-1 transitions in 
    between. Therefore, there must be nPk-1 substring transitions
    for each k. 
    
    In total, there will be n*n!-(n-1)-\sum(nPk-1) subarrays, for
    k=1 to n-1, which is equivalent to n*n!-\sum(nPk).

    Alternative solution with recurrence:
    ll ans=1,k=1;
    for(ll i=1;i<=n;i++){
      k=k*i%mod;
      ans=(ans*i+k-i)%mod;
    }*/