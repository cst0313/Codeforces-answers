//381A
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()//implement
{
    ll n, templ;
    cin >> n;
    deque<ll> d;
    for (ll i = 0; i < n; i++)
    {
        cin >> templ;
        d.push_back(templ);
    }
    ll a = 0;
    ll b = 0;
    bool turn = 1;
    while (d.size() != 0)
    {
        if (turn)
        {
            if (d.front() > d.back())
            {
                a += d.front();
                d.pop_front();
            }
            else
            {
                a += d.back();
                d.pop_back();
            }
        }
        else
        {
            if (d.front() > d.back())
            {
                b += d.front();
                d.pop_front();
            }
            else
            {
                b += d.back();
                d.pop_back();
            }
        }
        turn = !turn;
    }
    cout << a << " " << b << endl;
    return 0;
}