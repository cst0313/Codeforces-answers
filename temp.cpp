//233B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll s(ll k){//function for calculating the sum of digits
  ll a=0;
  while(k>=10){
    a+=k%10;
    k/=10;
  }
  a+=k;
  return a;
}

int main(){
  string str;
  cin>>str;
  ll dig=str.length();//basically log10 but I'm lazy
  ll n;
  n=stoll(str);
  //this lower bound is achieved by assuming every digit is a 9.
  ll lower_bound=max((ll)1,(-9*dig+(ll)floor(sqrt(81*dig*dig+4*n)))/2-1);//quadratic formula
  for(ll i=lower_bound;i<=sqrt(n);i++){
    if(n%i==0){
      if(i*i+s(i)*i==n){//direct check
        cout<<i;
        return 0;
      }
    }
  }
  cout<<-1;
  return 0;
}
