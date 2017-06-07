/**
ID: njuwz151
TASK: barn1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 200

using namespace std;

bool cmp(int m, int n);

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int m, s, c;
	int n[MAXN];
	int delta[MAXN];
	cin >> m >> s >> c;
	for(int i = 0; i < c; i++) {
		cin >> n[i];
	}
	if(m >= c) {
		cout << c << endl;
		return 0;
	}
	sort(n, n + c);
	/**
	* 用一块长木板可以覆盖所有的牛棚，找到m-1个空隙，那么就把牛棚分成了m块
	* 也就是说去掉m-1个最大的空隙，就能找到最短的木板 
	*/
	for(int i = 1; i < c; i++) {
		delta[i-1] = n[i] - n[i-1] - 1;
	}
	sort(delta, delta + c - 1, cmp);

	int min = n[c-1] - n[0] + 1;
	for(int i = 0; i < m-1; i++) {
		min -= delta[i];
	}
	cout << min << endl;
	
}

bool cmp(int m, int n) {
	return m > n;
}


