//617C
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d(ll x1,ll y1,ll x2,ll y2){//function for distance
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(){
    ll n,fx1,fy1,fx2,fy2,templ,templ2;
    cin>>n>>fx1>>fy1>>fx2>>fy2;
    vector<pair<ll,ll> > v;//somehow the compiler needs a space so here it is
    for(ll i=0;i<n;i++){
        cin>>templ>>templ2;
        v.push_back(make_pair(d(fx1,fy1,templ,templ2),d(fx2,fy2,templ,templ2)));//push distance of point to the first and second circle respectively
    }
    sort(v.begin(),v.end());//sort according to distance to the first circle
    ll ma[n];//records the maximum of the distance of points from n
    memset(ma,0,sizeof(ma));
    ll maxi=0;
    for(ll i=n-1;i>=0;i--){//reverse loop, since we are going to include the last few points in the second circle, and find the maximum required to include all the last few points
        maxi=max(maxi,v[i].second);//doing it
        ma[i]=maxi;//record it for later use
    }
    ll answer=min(v[n-1].first,maxi);//include all in the first circle or the second one
    maxi=0;//reset to use for the expansion of first circle
    for(ll i=0;i<n-1;i++){
        maxi=max(maxi,v[i].first);//include the ith point in the circle
        answer=min(answer,ma[i+1]+maxi);//check if the required has been minimized
    }
    cout<<answer;
    return 0;
}