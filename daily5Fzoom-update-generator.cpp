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
  cout<<endl;
  cout<<"                        if (date == \""<<date<<"\") {"<<endl;
  while(lessons--){
    cout<<"                            ";
    cin>>type;
    getline(cin,ts);
    getline(cin,ts);
    getline(cin,te);
    cout<<"if (time >= \""<<ts<<"\" && time < \""<<te<<"\") {"<<endl;
    cout<<"                                link = "<<type<<";"<<endl;
    cout<<"                            }"<<endl;
  }
  cout<<"                        }"<<endl;
  return 0;
}//shift option k to align
/*
3-29
7
math
8:15
8:59
bre
9:20
9:34
math
9:35
9:59
chem
10:30
10:55
bre
11:10
11:20
physics
11:25
11:59
physics
12:00
12:35
fin
12:35
23:59
*/