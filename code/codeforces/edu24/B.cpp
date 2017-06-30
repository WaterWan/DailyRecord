#include <iostream>

using namespace std;

const int maxn = 105;

int used[maxn];
int l[maxn];
int a[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> l[i];
	}
	for(int i = 1; i < m; i++) {
		int delta = l[i] - l[i-1];
		if(delta <= 0) {
			delta = n + delta;
		}
		if(l[i-1] != used[delta] && used[delta] != 0) {
			cout << "-1" << endl;
			return 0;
		}
		a[l[i-1]] = delta;
		used[delta] = l[i-1];
	}
	if(a[1] == 0) {
		for(int i = 1; i < maxn; i++) {
			if(!used[i]) {
				a[1] = i;
				used[i] = true;
				break;
			}
		}
	}
	cout << a[1];
	for(int i = 2; i <= n; i++) {
		if(a[i] == 0) {
			for(int j = 1; j < maxn; j++) {
				if(!used[j]) {
					a[i] = j;
					used[j] = true;
					break;
				} 
			} 
		}
		cout << " " << a[i];
	}
	cout << endl;
	return 0;
} 
