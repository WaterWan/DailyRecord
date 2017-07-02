#include <iostream>

using namespace std;

const int maxn = 1005;

int main() {
	int n, m;
	char a[maxn];
	char b[maxn];
	int add[maxn];
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int min = 9999;
	int min_turn = -1;
	for(int i = 0; i <= m - n; i++) {
		int diff = 0;
		for(int j = 0; j < n; j++) {
			if(a[j] != b[j+i]) {
				diff++;
			}
		}
		if(diff < min) {
			min = diff;
			min_turn = i;
		}
	}
	int n_ptr = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] != b[i+min_turn]) {
			add[n_ptr] = i+1;
			n_ptr++;
		}
	}
	cout << n_ptr << endl;
	if(n_ptr > 0) {
		cout << add[0];
	}

	for(int i = 1; i < n_ptr; i++) {
		cout << " " << add[i];
	}
	cout << endl;
}
