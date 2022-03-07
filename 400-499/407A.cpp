//407A=408C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool issquare(ll x){//function to check if it is a square or not
  if(floor(sqrt(x))*floor(sqrt(x))==x){
    return 1;
  }
  return 0;
}

int main(){
  bool go=0;//boolean for skipping loops
  ll x,y;
  cin>>x>>y;
  if(x>y){
    swap(x,y);
  }
  x=x*x;//I should not have squared this, but I was too lazy to change every x afterwards to x*x so here it is
  y=y*y;
  vector <pair<ll,ll>>v;//vector for sum of squares that will make the short side
  vector <pair<ll,ll>>a;//vector of answers
  for(ll i=1;i<=floor(sqrt((ld)x));i++){//check
    if(i*i!=x and issquare(x-i*i)){//got a pair
      ll g=floor(sqrt(x-i*i));
      v.push_back(make_pair(min(i,g),max(i,g)));//push
    }
  }
  for(auto x:v){//for all possible pairs that make up a short side:
    for(ll i=1;i<=floor(sqrt((ld)y));i++){//this is for the additional chunk above the short side
      //you can draw a graph and work out the math. My setup is with right angle at (0,0) and short side slanted positive right direction
      ll h1=x.first+i;
      ld w1=x.first*h1/(x.second);
      if(floor(w1)==w1 and w1*w1+h1*h1==y){//we have a match for long side
        go=1;
        a.push_back(make_pair(x.second,x.first));//the three desired coordinates
        a.push_back(make_pair(-1*w1,h1));
        a.push_back(make_pair(0,0));
        break;
      }
      h1=x.second+i;//swap long, short side
      w1=x.second*h1/(x.second);
      if(floor(w1)==w1 and w1*w1+h1*h1==y){//check again
        go=1;
        a.push_back(make_pair(x.first,x.second));
        a.push_back(make_pair(-1*w1,h1));
        a.push_back(make_pair(0,0));
        break;
      }
    }
    if(go){//save time, shall we?
      break;
    }
  }
  if(go){//got an answer
    cout<<"YES"<<endl;
    cout<<a[0].first<<" "<<a[0].second<<endl;
    cout<<a[1].first<<" "<<a[1].second<<endl;
    cout<<a[2].first<<" "<<a[2].second<<endl;
  }else{//ain't got no answer
    cout<<"NO";
  }
  return 0;
}