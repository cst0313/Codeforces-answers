//1093A
#include <bits/stdc++.h>

using namespace std;
int main(){//since the checker has a large time limit, I did this under time conditions
    int n;
    cin>>n;
    int templ;
    for(int i=0;i<n;i++){
        int answer=0;
        cin>>templ;
        while(templ>7){//we roll a 7
            templ-=7;
            answer++;
        }
        //even if we have a remainder of 1 in the end, we can swap 1-7 for 2-6, so there is no problem(and we won't start with 1 only)
        if(templ==0){//all 7s
            cout<<answer<<endl;
        }else{//have a remainder, need one more dice roll
            cout<<answer+1<<endl;
        }
    }
    return 0;
}