#include <bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin>>n;
    if(n==3){cout<<5; return 0;}
    int x=ceil(sqrt(2*n-1));
    cout<<x+1-x%2;
    return 0;
}