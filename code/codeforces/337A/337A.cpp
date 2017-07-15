#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int maxn = 1005;

int main() {
	int n, m;
	cin >> n >> m;
	int f[maxn];
	int delta[maxn];
	for(int i = 0; i < m; i++) {
		cin >> f[i];
	}
	sort(f, f + m, less<int>());
	for(int i = 0; i <= m - n;i++) {
		delta[i] = f[i + n - 1] - f[i];
	}
	sort(delta, delta + m - n + 1, less<int>());
	cout << delta[0] << endl;
	return 0;
} 
