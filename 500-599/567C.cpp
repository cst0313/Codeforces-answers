//567C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n,k;
    cin>>n>>k;
    map<ll,ll>ml,mr;//map for numbers on the left and right
    ll answer=0;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        ml[a[i]]++;//start from end, all numbers initially on left
    }
    ml[a[n-1]]--;//last number can't count
    mr[a[n-1]]++;
    for(ll i=n-2;i>=1;i--){
        ml[a[i]]--;//remove from left, since we can't count middle element as that on left
        if(a[i]%k==0){
            answer+=ml[a[i]/k]*mr[a[i]*k];//first and third element
        }
        mr[a[i]]++;//same here, we don't add after calculating, since middle element doesn't count as that on right
    }
    cout<<answer<<endl;
    return 0;
}