#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
int a[maxn];
int main() {
	int x;
	cin >> x;
	int n = x * 2;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int tot = inf;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i <= j) {
				continue;
			}
			int t1 = a[i];
			int t2 = a[j];
			a[i] = a[j] = 0;
			sort(a, a + n);
			int temp_tot = 0;
			for(int t = 0; t < n; t += 2) {
				temp_tot += a[t+1] - a[t];
			}
			tot = min(tot, temp_tot);
			a[0] = t1;
			a[1] = t2;
			sort(a, a + n);
		}
	}
	cout << tot << endl;
}
