//1413A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n,templ,templ2,templ3;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>templ;
        for(ll j=0;j<templ/2;j++){//pair them two at a time
            cin>>templ2>>templ3;
            ll g=(templ2*templ3)/__gcd(templ2,templ3);// we find the lcm of the two numbers
            cout<<-1*g/templ2<<" "<<g/templ3<<" ";
        }
      //actually, could have just done swap cout<<-1*templ3<<" "<<templ2, but was under competition and kinda just went the hard way
        cout<<endl;
    }
    return 0;
}