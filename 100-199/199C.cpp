//199C
#include <bits/stdc++.h>

using namespace std;
//note that an implementation solution will not work, since if it is 100000 100000 100000 ..., then the repeated function of ax+b for 100000 times will exceed any big number limit.
int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long times=0;//counter of number of times
    long long cur=1;//current number after multiplication
    while(cur<=d){
        cur=a*cur+b;
        times++;//we want the number of functions applied just before we hit d
    }
    cout<<max((long long)0,c-times+1);//if our original already exceeded the number of times, we will get a negative number, so minimum of times is set at 0.
}