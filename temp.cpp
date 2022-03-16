//349C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
 
int main(){
  string date;
  getline(cin,date);
  ll lessons;
  cin>>lessons;
  string type;
  string ts,te;
  cout<<"           if(date==\""<<date<<"\"){"<<endl;
  while(lessons--){
    cout<<"           ";
    cout<<"  ";
    cin>>type;
    getline(cin,ts);
    getline(cin,ts);
    getline(cin,te);
    cout<<"if(time>=\""<<ts<<"\" && time<\""<<te<<"\"){"<<endl;
    cout<<"               link="<<type<<";"<<endl;
    cout<<"             }"<<endl;
  }
  cout<<'}'<<endl;
  return 0;
}
/*
3-24
math
8:15
8:45
bre
9:20
9:35
physics
9:35
9:50
math
10:35
10:55
break
10:
fin
12:35
23:59
*/