//914A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool issquare(ll n){//function to check if the number is not a square
    return floor(sqrt(n))*floor(sqrt(n))==n;
}

int main(){
    ll n,templ;
    cin>>n;
    ll answer=-99999999999;//just for safety, could use -1
    for(ll i=0;i<n;i++){
        cin>>templ;
        if(!issquare(templ)){//implementation: find the largest non-square number
            answer=max(answer,templ);
        }
    }
    cout<<answer<<endl;
  return 0;
}