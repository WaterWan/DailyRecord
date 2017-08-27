// 能够过掉30%的样例 
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int maxn = 505;
int n, m;
string s[maxn];
int hashs[maxn][maxn];

void get_hash(int x) {
	memset(hashs, 0, sizeof hashs);
	for(int i = 0; i < n + 1 - x; i++) {
		for(int j = 0; j < m + 1 - x; j++) {
//			for(int i1 = 0; i1 < x; i1++) {
//				for(int j1 = 0; j1 < x; j1++) {
//					hashs[i][j] += (s[i][j] - 'a') * (i1 + 1); 
//				}
//			}
			hashs[i][j] = s[i][j] - 'a';
		}
	}
}

bool matrix_same(int x1, int y1, int x2, int y2, int l) {
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++) {
			if(s[x1 + i][y1 + j] !=s[x2 + i][y2 + j]) {
				return false;
			}
		}
	}
	return true;
}

int find(int x) {
	get_hash(x);
	for(int i1 = 0; i1 < n + 1 - x; i1++) {
		for(int j1 = 0; j1 < m + 1 - x; j1++) {
			for(int i2 = 0; i2 < n + 1 - x; i2++) {
				for(int j2 = 0; j2 < m + 1 - x; j2++) {
					if(!(i1 == i2 && j1 == j2) && hashs[i1][j1] == hashs[i2][j2]) {
						if(matrix_same(i1, j1, i2, j2, x)) {
							return x;
						}
					}
				}
			} 
		} 
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int max_len = 0;
	int max_search;
	int min_search = 0;
	if(m == n) {
		max_search = m - 1;
	} else {
		max_search = min(m, n);
	}
	while(min_search < max_search) {
		int mid = (min_search + max_search) / 2;
		int t = find(mid);
		if(t > 0) {
			min_search = mid + 1;
			max_len = max(max_len, t);
		} else {
			max_search = mid;
		}
	}
	cout << max_len << endl;
}
