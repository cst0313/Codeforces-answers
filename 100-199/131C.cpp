//131C.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector <pair<ll,ll>>
#define sll set<ll>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first //no brackets are needed!
#define se second
#define mp make_pair
#define pb push_back
#define sd(n) scanf("%lld",&n)
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
static const double pi = acos(-1);
//LLONG_MAX
ld answer{0};
char tempc{' '};
ll templ{0};
ll templ2{0};
ll templ3{0};
ll templ4{0};
string temps;
ll C(ll n, ll r){
    ll result(1);
       for (ll i = 0; i < r; ++i) {
           result *= (n - i);
           result /= (i + 1);
       }
       return result;
}
const ll mod=1000000007;
int32_t main(){
 fast_io;
 ll n,m,t;
 cin>>n>>m>>t;
 for(ll i=0;i<=t-5;i++){
   answer+=C(n,4+i)*C(m,t-i-4);
     if(answer>mod){
         templ=floor(answer/mod);
         templ2+=templ;
         answer-=mod*templ;
     }
 }
 cout<<setprecision(100)<<answer+templ2*mod;
 return 0;
}