//464A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n,p;
  cin>>n>>p;
  string s;
  cin>>s;
  ll pos=n-1;
  s[pos]++;
  while(pos>=0 and pos<n){
    if(s[pos]-'a'>=p){//digit carrying
      s[pos]='a';
      pos--;
      if(pos==-1){
        break;
      }
      s[pos]++;
    }else if(pos!=0 and (s[pos]==s[pos-1]) or (pos>1 and s[pos]==s[pos-2])){//increment if not end, not equal to prev
      s[pos]++;
    }else{
      pos++;
    }
  }
  if(pos==-1){
    cout<<"NO";
  }else{
    cout<<s<<endl;
  }
  return 0;
}
