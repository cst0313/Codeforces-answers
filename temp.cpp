//199B
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ld d(ld x1,ld y1,ld x2,ld y2){
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool intersect(ld x1,ld y1,ld r1,ld x2,ld y2,ld r2){
  ld dis=d(x1,y1,x2,y2);
  if(dis<=max(r1,r2)){//included
    if(max(r1,r2)-dis>=min(r1,r2)){
      return 0;
    }else{
      return 1;
    }
  }else{
    if(r1+r2>dis){//outside
      return 1;
    }else{
      return 0;
    }
  }
}

bool check(ld x1,ld y1,ld x2,ld y2,ld r1,ld r2,ld r3){//full circle in range exception
  if(d(x1,y1,x2,y2)-r3>=min(r1,r2) and d(x1,y1,x2,y2)+r3<=max(r1,r2)){
    return 0;
  }else{
    return 1;
  }
}

bool shaded(ld x,ld y,ld x1,ld y1,ld r1,ld r2,ld r3){
  ld dis=d(x,y,x1,y1);
  if(dis+r3>min(r1,r2) and dis+r3<=max(r1,r2)){//center circle, reject since blacked out
    return 1;
  }
  return 0;
}

ll answer=0;
int main(){
  ld a,b,r,R,a1,b1,r1,R1;
  cin>>a>>b>>r>>R;
  cin>>a1>>b1>>r1>>R1;
  if(!intersect(a,b,r,a1,b1,r1) and !intersect(a,b,r,a1,b1,R1)){//inner 1st
    if(!shaded(a,b,a1,b1,r1,R1,r)){
        answer++;
        //cout<<"1";
    }
  }
  if(!intersect(a,b,R,a1,b1,r1) and !intersect(a,b,R,a1,b1,R1)){//outer 1st
    if(!shaded(a,b,a1,b1,r1,R1,R)){
      answer++;
      //cout<<"2";
    }
  }
  if(!intersect(a,b,r,a1,b1,r1) and !intersect(a,b,R,a1,b1,r1)){//inner 2nd
    if(!shaded(a,b,a1,b1,r,R,r1)){
      answer++;
      //cout<<"3";
    }
  }
  if(!intersect(a,b,r,a1,b1,R1) and !intersect(a,b,R,a1,b1,R1)){//outer second
    if(!shaded(a,b,a1,b1,r,R,R1)){
      answer++;
      //cout<<"4";
    }
  }
  cout<<answer;
  return 0;
}