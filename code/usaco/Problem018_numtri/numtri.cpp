/**
ID: njuwz151
TASK: numtri
LANG: C++
*/
#include <bits/stdc++.h>

#define MAXN 1005

using namespace std;

int a[MAXN][MAXN];

int d[MAXN][MAXN];

int main() {
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	int r;
	cin >> r;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	
	memset(d, 0, sizeof d);
	for(int i = 0; i < r; i++) {
		d[r-1][i] = a[r-1][i];
	}
	for(int i = r - 2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			d[i][j] = a[i][j] + max(d[i+1][j], d[i+1][j+1]);
		}
	}
	cout << d[0][0] << endl;
}
