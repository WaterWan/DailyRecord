#include <iostream>

using namespace std;

const int maxn = 30005;

int main() {
	int n, t;
	int a[maxn];
	cin >> n >> t;
	bool ok = false;
	if(t == 1) {
		ok = true;
	}
	for(int i = 1; i < n; i++) {
		cin >> a[i];
	}
	int ptr = 1;
	while(ptr < t) {
		ptr += a[ptr];
	}
	if(ptr == t) {
		ok = true;
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}
