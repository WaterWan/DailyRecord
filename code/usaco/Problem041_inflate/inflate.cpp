/**
ID: Wan Zhong
TASK: inflate
LANG: C++11
**/ 
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int m, n;
const int maxn = 10010;
int points[maxn];
int minutes[maxn];
int dp[maxn];

void get_input() {
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		cin >> points[i] >> minutes[i];
	}
}

void init() {
	memset(dp, 0, sizeof dp);
}

int solve() {
	for(int i = 0; i < n; i++) {
		for(int j = minutes[i]; j <= m; j++) {
			dp[j] = max(dp[j], dp[j - minutes[i]] + points[i]);
		}
	}
	return dp[m];
}

int main() {
	get_input();
	init();
	cout << solve() << endl;
}
