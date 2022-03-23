//146B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string mask(ll x){//straight up implementation
    string s=to_string(x);
    string m="";//mask, but can't use same name since function name is mask
    for(int i=0;i<s.length();i++){
        if(s[i]-'0'==4 or s[i]-'0'==7){
            m+=s[i];//add the character 4 or 7 to the mask
        }
    }
    return m;
}
int main(){
  ll a;
  string b;
  cin>>a>>b;
  ll cur=a+1;//note in the problem statement answer>a, not >=a
  while(mask(cur)!=b){//increment until mask of current number is b
      cur++;
  }
  cout<<cur;
  return 0;
}
