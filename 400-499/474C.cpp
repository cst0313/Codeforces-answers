//474C
#include <bits/stdc++.h>
using namespace std;
int distance(int x1, int y1, int x2, int y2){//no sqrt cuz we don't really need it, and it wastes space
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool square(pair<int,int>one,pair<int,int>two,pair<int,int>three,pair<int,int>four){
  set<int>s;
  s.clear();
  //we insert each pair of points 4C2=6
  s.insert(distance(one.first,one.second,two.first,two.second));
  s.insert(distance(one.first,one.second,three.first,three.second));
  s.insert(distance(one.first,one.second,four.first,four.second));
  s.insert(distance(two.first,two.second,three.first,three.second));
  s.insert(distance(two.first,two.second,four.first,four.second));
  s.insert(distance(three.first,three.second,four.first,four.second));
  if(s.find(0)!=s.end()){//overlapping points have zero distance
    return 0;
  }
  return s.size()==2;//diagonals and sides (note only squares have this property, not rectangles, rhombuses etc.)
}
int main() 
{
    int n;
    cin>>n;
    int answer=999;
    for(int i=0;i<n;i++){//n cases
      int answer=999;//initialize
      vector<pair<int,int>> a;
      vector<pair<int,int>> b;
      vector<pair<int,int>> c;
      vector<pair<int,int>> d;
      int t1,t2,t3,t4,ts1;//temp store 1 and get points
      cin>>t1>>t2>>t3>>t4;
      a.push_back(make_pair(t1,t2));//counterclockwise 0
      ts1=t1;
      t1=t4+t3-t2;//this rotation is through the rotation matrix 
      t2=ts1-t3+t4;//here note ts1 is used since the old t1 is changed
      a.push_back(make_pair(t1,t2));//counterclockwise 1
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      a.push_back(make_pair(t1,t2));//counterclockwise 2
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      a.push_back(make_pair(t1,t2));//counterclockwise 3
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      cin>>t1>>t2>>t3>>t4;//get second point
      b.push_back(make_pair(t1,t2));//counterclockwise 0
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      b.push_back(make_pair(t1,t2));//counterclockwise 1
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      b.push_back(make_pair(t1,t2));//counterclockwise 2
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      b.push_back(make_pair(t1,t2));//counterclockwise 3
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      cin>>t1>>t2>>t3>>t4;//third point
      c.push_back(make_pair(t1,t2));//counterclockwise 0
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      c.push_back(make_pair(t1,t2));//counterclockwise 1
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      c.push_back(make_pair(t1,t2));//counterclockwise 2
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      c.push_back(make_pair(t1,t2));//counterclockwise 3
      t1=t4+t3-t2;
      t2=t1-t3+t4;
      cin>>t1>>t2>>t3>>t4;//fourth point
      d.push_back(make_pair(t1,t2));//counterclockwise 0
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      d.push_back(make_pair(t1,t2));//counterclockwise 1
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      d.push_back(make_pair(t1,t2));//counterclockwise 2
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      d.push_back(make_pair(t1,t2));//counterclockwise 3
      ts1=t1;
      t1=t4+t3-t2;
      t2=ts1-t3+t4;
      for(int j=0;j<4;j++){//for each pair we loop
        for(int k=0;k<4;k++){
          for(int l=0;l<4;l++){
            for(int m=0;m<4;m++){
              if(square(a[j],b[k],c[l],d[m])){//check square
                answer=min(answer,j+k+l+m);//j+k+l+m is the current number of moves that achieves a square, but we need minimum
              }
            }
          }
        }
      }
      if(answer>=16){//cuz most 16, but 16 means zero
        cout<<-1<<endl;
      }else{
        cout<<answer<<endl;
      }
    }
    return 0;
}