#include <bits/stdc++.h>

#define MAXN 8

using namespace std;

typedef struct {
	int x;
	int y;
} Queen;

Queen queen[MAXN];
int pos[MAXN][MAXN];

bool attack() {
	for(int i = 0; i < MAXN; i++) {
		for(int j = 0; j < MAXN; j++) {
			if(i == j) {
				continue;
			}
			if(queen[i].x == queen[j].x) {
				return true;
			}
			if(queen[i].y == queen[j].y) {
				return true;
			}
			if(queen[i].x - queen[j].x == queen[i].y - queen[j].y) {
				return true;
			}
			if(queen[i].x - queen[j].x == queen[j].y - queen[i].y) {
				return true;
			}
		}
	}
	return false;
}

int dfs(int n) {
	int total = 0;
	if(n == MAXN) {
		if(attack()) {
			return 0;
		}
		for(int i = 0; i < MAXN; i++) {
			for(int j = 0; j < MAXN; j++) {
				cout << pos[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return 1;
	}

	for(int i = 0; i < MAXN; i++) {
		if(pos[n][i] != 0) {
			continue;
		} 
		pos[n][i] = 1;
		queen[n].x = n;
		queen[n].y = i;
		total += dfs(n+1);
		pos[n][i] = 0;
		queen[n].x = 0;
		queen[n].y = 0;
	}
	return total;
}

int main() {
	for(int i = 0; i < MAXN; i++) {
		queen[i].x = queen[i].y = 0;
	}
	for(int i = 0; i < MAXN; i++) {
		for(int j = 0; j < MAXN; j++) {
			pos[i][j] = 0;
		}
	}
	cout << dfs(0) << endl;
} 
