//131A.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vi vector<int>
#define vll vector<ll>
#define vpll vector <pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first //no brackets are needed!
#define se second
#define mp make_pair
#define pb push_back
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
static const double pi = acos(-1);
//LLONG_MAX 
string answer{""};
char tempc{' '};
ld templd;
ll templ{0};
ll templ2{0};
ll templ3{0};
ll templ4{0};
string temps;
const ll mod=1000000007;
int32_t main(){
 fast_io;
 string s;
 cin>>s;
 for(int i=1;i<s.length();i++){
   if(islower(s[i])){
     templ=1;
     break;
   }
 }
 if(templ==0){
   for(char x:s){
     if(islower(x)){
       x=toupper(x);
       answer+=x;
     }else{
       x=tolower(x);
       answer+=x;
     }
   }
 }
 if(answer==""){
   cout<<s;
 }else{
   cout<<answer;
 }
 return 0;
}