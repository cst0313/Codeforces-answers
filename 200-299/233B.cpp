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
  n=stoll(str);//string to long long function
  //this lower bound is achieved by assuming every digit is a 9.
  ll lower_bound=max((ll)1,(-9*dig+(ll)floor(sqrt(81*dig*dig+4*n)))/2-1);//quadratic formula
  for(ll i=lower_bound;i<=sqrt(n);i++){
    if(n%i==0){//this other if loop is to prevent the slow s(i) function from executing everytime, just notice i must be a factor of n
      if(i*i+s(i)*i==n){//direct check
        cout<<i;
        return 0;
      }
    }
  }
  cout<<-1;//none are found: it is easy to prove upper bound is sqrt(n).
  //assume the number is greater than sqrt(n). But then the equation x^2+s(x)*x>x^2>n, which is a contradiction.
  return 0;
}
