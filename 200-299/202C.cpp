//202C
#include <bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin>>n;
    if(n==3){cout<<5; return 0;}//edge case
    int x=ceil(sqrt(2*n-1));//reader is encouraged to find pattern
    cout<<x+1-x%2;
    return 0;
}