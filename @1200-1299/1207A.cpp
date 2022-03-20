//1207A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll templ,templ2,templ3;
ll h,c;//money earned for each type of burger
int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>templ>>templ2>>templ3;//buns, beef, chicken
        cin>>h>>c;
        ll ans1=0;//1st: greedy with beef
        ll ans2=0;//2nd: greedy with chicken
        ll buns=templ;
        ll beef=templ2;
        ll chicken=templ3;
        //here there is definitely some math equation, but since the constraints are small and I was under competition, I just went for the loop
        while(buns>=2 and beef>0){//make all the beef you can
            ans1+=h;
            beef--;
            buns-=2;
        }
        while(buns>=2 and chicken>0){//make all the chicken you can 
            ans1+=c;
            chicken--;
            buns-=2;
        }
        //remember to reset the bun, beef and chicken count, or else we have nothing left
        buns=templ;
        beef=templ2;
        chicken=templ3;
        while(buns>=2 and chicken>0){//make all the chicken you can
            ans2+=c;
            chicken--;
            buns-=2;
        }
        while(buns>=2 and beef>0){//make all the beef you can
            ans2+=h;
            beef--;
            buns-=2;
        }
        cout<<max(ans1,ans2)<<endl;//maximum of both will be our answer
    }
  return 0;
}