//199B 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ld d(ld x1,ld y1,ld x2,ld y2){//distance shorthand function
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool intersect(ld x1,ld y1,ld r1,ld x2,ld y2,ld r2){//this will determine if there are intersection points. Of course, once there are intersections, we reject
  ld dis=d(x1,y1,x2,y2);//prevent calculating it for multiple times
  if(dis<=max(r1,r2)){//second center within first circle
    if(max(r1,r2)-dis>=min(r1,r2)){//larger one includes the whole smaller circle
      return 0;//no intersection
    }else{
      return 1;//intersection
    }
  }else{//center not within another circle
    if(r1+r2>dis){//condition for intersection
      return 1;
    }else{//here from the question definition, if the circles are "kissing" then we can still draw two circles
      return 0;
    }
  }
}

bool shaded(ld x,ld y,ld x1,ld y1,ld r1,ld r2,ld r3){
  ld dis=d(x,y,x1,y1);
  if(dis+r3>min(r1,r2) and dis+r3<=max(r1,r2)){//center circle, reject since blacked out. >min is since if it is internally tangent to minimum range, it is ok. <=max is since if it is the 2nd circle of all 3, and the furthest side is tangent to the external range, we still reject, so include the maximum.
    return 1;
  }
  return 0;
}

ll answer=0;
int main(){
  ld a,b,r,R,a1,b1,r1,R1;
  cin>>a>>b>>r>>R;
  cin>>a1>>b1>>r1>>R1;
  //another observation here is we can only have 0-4 circles, and the four is created by 2*2
  if(!intersect(a,b,r,a1,b1,r1) and !intersect(a,b,r,a1,b1,R1)){//inner 1st
    if(!shaded(a,b,a1,b1,r1,R1,r)){
        answer++;
    }
  }
  if(!intersect(a,b,R,a1,b1,r1) and !intersect(a,b,R,a1,b1,R1)){//outer 1st
    if(!shaded(a,b,a1,b1,r1,R1,R)){
      answer++;
    }
  }
  if(!intersect(a,b,r,a1,b1,r1) and !intersect(a,b,R,a1,b1,r1)){//inner 2nd
    if(!shaded(a,b,a1,b1,r,R,r1)){
      answer++;
    }
  }
  if(!intersect(a,b,r,a1,b1,R1) and !intersect(a,b,R,a1,b1,R1)){//outer second
    if(!shaded(a,b,a1,b1,r,R,R1)){
      answer++;
    }
  }
  cout<<answer;
  return 0;
}