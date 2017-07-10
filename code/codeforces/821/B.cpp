#include <iostream>

typedef long long ll;

using namespace std;

ll sum_of_n(ll x);

int main() {
	int m, b;
	cin >> m >> b;
	ll best = 0;
	for(ll y = 0; y <= b; y++) {
		ll x = m * (b - y);
		ll t = (x + 1) * sum_of_n(y) + (y + 1) * sum_of_n(x);
		best = max(t, best);
	}
	cout << best << endl;
} 

ll sum_of_n(ll x) {
	return x * (x + 1) / 2;
}


