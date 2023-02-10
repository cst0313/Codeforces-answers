// 402C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { // (╯°□°）╯︵ ┻━┻
	//あきらめないで
	int tests;
	ll lines = 0;
	ll n, p;
	cin >> tests;
	while (tests--) {
		cin >> n >> p;
		lines = 2 * n + p;
		for (ll i = 1; i < n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				cout << i << " " << j << endl;
				lines--;
				if (lines == 0) {
					break;
				}
			}
			if (lines == 0) {
				break;
			}
		}
	}
	return 0;
}