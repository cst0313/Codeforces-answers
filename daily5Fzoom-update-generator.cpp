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
3-28
7
math
8:15
8:45
bre
9:20
9:34
drive
9:35
10:30
drive
10:35
10:55
break
11:10
11:20
chem
11:20
11:59
fin
13:05
23:59
*/