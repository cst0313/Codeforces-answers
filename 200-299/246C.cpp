//246C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() 
{
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    //observe we can output each and fix maximum few and iterate smaller numbers since the maximum is only n(n+1)/2
    ll save[n];
    for(ll i=0;i<n;i++){
      for(ll j=n-1;j>=i;j--){
        cout<<i+1<<" ";
        for(ll q=0;q<i;q++){//save since the front part is same
          cout<<save[q]<<" ";
        }
        cout<<a[j-i]<<endl;
        k--;
        if(k==0){
          return 0;
        }
      }
      save[i]=a[n-i-1];//setup for next set
    }
    return 0;
}
