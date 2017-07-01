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
		if(a[l[i-1]] == 0) {
			if(used[delta]) {
				cout << "-1" << endl;
				return 0;
			}
			a[l[i-1]] = delta;
			used[delta] = a[l[i-1]];
			continue;
		} 
		if(delta != a[l[i-1]]) {
			cout << "-1" << endl;
			return 0;
		}
		
	}
	
	for(int i = 1; i <= n; i++) {
		if(!a[i]) {
			for(int j = 1; j <= n; j++) {
				if(!used[j]) {
					used[j] = true;
					a[i] = j;
					break;
				}
			}
		}
	}
	cout << a[1];
	for(int i = 2; i <= n; i++) {
		cout << " " << a[i];
	}
	cout << endl;
	return 0;
} 
