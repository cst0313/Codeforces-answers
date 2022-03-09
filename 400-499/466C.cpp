//466C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n;
  cin>>n;
  ll a[n];
  ll sum=0;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  if(sum%3!=0){//trivially (as mathematicians say), we cannot split the sum
    cout<<0;
    return 0;
  }
  for(ll i=1;i<n;i++){
    a[i]+=a[i-1];//prefix sum trick, we can cut front if the sum before it is sum/3. cut back if 2*sum/3, forget about doing it in the middle
  }
  if(sum==0){//for this case, the sum of all numbers is zero, so the front and back will both be zero
    ll zerocount=0;
    for(ll i=0;i<n;i++){
      if(a[i]==0){
        zerocount++;//count the number of zeroes
      }
    }
    zerocount--;//put two lines between the gaps of the zeroes to split sum
    //example: 00000. then you can put 2 'sticks' within the 4 gaps. total number of ways is 4C2, or 4*(4-1)/2 by formula
    cout<<max((ll)0,((zerocount-1)*zerocount)/2);//prevent -1/2
    return 0;
  }
  ll fcount=0;//found frontcut
  ll bcount=0;//found backcut
  queue<bool>q;//save a teeny weeny bit of memory
  for(ll i=0;i<n;i++){
    if(a[i]==sum/3){//if we can use it as a frontcut
      fcount++;
      q.push(0);//indicate frontcut available
    }else if(a[i]==2*sum/3){//we can use it as a backcut
      bcount++;
      q.push(1);//indicate backcut available
    }
  }
  ll answer=0;
  while(q.size()>0){
    if(q.front()){//if front is 1->backcut available
      bcount--;//one less backcut available for the other frontcuts, since you can't cut the back then cut the front
      if(bcount==0){//just a bunch of fs, save time
          break;
      }
    }else{
      fcount--;//actually not really useful, but whatever
      answer+=bcount;//we can have bcount backcut choices
    }
    q.pop();
  }
  cout<<answer<<endl;
  return 0;
}
