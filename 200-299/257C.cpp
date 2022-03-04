//257C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
const ld pi=acos(-1);
int main() {
  ll n;
  cin>>n;
  ld templ,templ2;
  vector<ld>v;//for the angles from positive x-axis, anti-clockwise
  for(ll i=0;i<n;i++){
    cin>>templ>>templ2;
    if(templ>0 and templ2>0){//I quadrant
      v.pb(atan(templ2/templ));//tangent is trigonometry: to find the angle given x and y coordinates
    }else if(templ>0 and templ2<0){//IV quadrant
      v.pb(3*pi/2+atan(-1*templ/templ2));//remember to add 270 degrees
    }else if(templ<0 and templ2>0){//II
      v.pb(pi/2+atan(-1*templ/templ2));//90 degrees ahead
    }else if(templ<0 and templ2<0){//III
      v.pb(pi+atan(templ2/templ));//180 ahead
    }else if(templ==0){//can't divide by zero, so we do some edge cases handling
      if(templ2>0){//(0,y) is 90
        v.pb(pi/2);
      }else{//(0,negative number) is 180
        v.pb(3*pi/2);
      }
    }else if(templ2==0){
      if(templ>0){//(x,0) is 0
        v.pb(0);
      }else{//(negative number,0) is 180
        v.pb(pi);
      }
    }
  }
  sort(v.begin(),v.end());//sort by degrees
  ld ma=-1;//maximum angle: note long double data type
  for(ll i=0;i<v.size()-1;i++){
    ma=max(ma,v[i+1]-v[i]);//we want to exclude the maximum angle between points
  }
  ma=max(ma,2*pi-v[v.size()-1]+v[0]);//since it is circular, we patch up the last point of the IV quadrant and first point
  cout<<fixed<<setprecision(10)<<(2*pi-ma)*180/pi;//exclude largest angle, output in degrees
  return 0;
}