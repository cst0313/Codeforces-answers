//337C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1000000009;
ll answer=0;
ll n,m,k;
ll binpow(ll a, ll b){//I tried O(n), not ok, so we do a binary exponentiation
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a =(a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}
int main(){//what a nice problem
    cin>>n>>m>>k;
    ll correctq=m;//number of correct questions
    ll incorrectq=n-m;//number of incorrect questions
    if(correctq>(incorrectq+1)*(k-1)){//k-1(X)k-1(X)k-1(X)...., maximum without doubling is the right hand side of the inequality
        ll rem=correctq-(incorrectq)*(k-1);//remaining questions after (X)k-1...(X)k-1
        ll times=rem/k;//the number of times we have to double 
        /*for(ll i=0;i<times;i++){(TLE)
            answer+=k;
            answer=answer<<1;
            answer%=mod;
        }*/
        //instead of nested functions    2( 2(x+k) +k), we note this expands to 2^n*x + (2^(n+1)-2)*k.
        //since the initial number, x is equal to zero, the points we get from the first section is (2^(n+1)-2)*k.
        answer+=k*(binpow(2,times+1)-2);//this equation is much faster, by speeding up the exponentiation of 2.
        answer%=mod;//of course remember to 
        answer+=correctq-times*k;
    }else{
        cout<<m;//no problems
        return 0;
    }
    cout<<(answer+mod)%mod;//WA on test 44 (-4 instead of 10000000005) due to the lack of +mod -_- just do it
    return 0;
}
