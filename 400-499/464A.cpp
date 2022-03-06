//465C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n,p;
  cin>>n>>p;
  string s;
  cin>>s;
  ll pos=n-1;//start from incrementing the end, since it affects least
  s[pos]++;//next
  while(pos>=0 and pos<n){//limits for position of string
    if(s[pos]-'a'>=p){//digit carrying
      s[pos]='a';
      pos--;
      if(pos==-1){
        break;
      }
      s[pos]++;
    }else if(pos!=0 and (s[pos]==s[pos-1]) or (pos>1 and s[pos]==s[pos-2])){//increment, if there is two to check for then check
      s[pos]++;
    }else{
      pos++;
    }
  }
  if(pos==-1){//incrementing to max, didn't work at all
    cout<<"NO";
  }else{
    cout<<s<<endl;
  }
  return 0;
}
