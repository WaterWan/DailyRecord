/**
ID: njuwz151
TASK: milk3
LANG: C++
*/ 

#include <bits/stdc++.h>

#define MAXN 20

using namespace std;

int MAXA, MAXB, MAXC;
bool used[MAXN + 1][MAXN + 1][MAXN + 1];
bool visit[MAXN + 1];

void dfs(int A, int B, int C) {
	if(used[A][B][C]) {
		return;
	} else {
		used[A][B][C] = 1;
	}
	if(A == 0) {
		visit[C] = 1;
	}
	
	
	// CÍùAµ¹Ë® 
	if(C >= MAXA - A) {
		dfs(MAXA, B, C - MAXA + A);
	} else {
		dfs(A + C, B, 0);
	}
	
	if(C >= MAXB - B) {
		dfs(A, MAXB, C - MAXB + B);
	} else {
		dfs(A, B + C, 0);
	}
	
	if(A >= MAXC - C) {
		dfs(A - MAXC + C, B, MAXC);
	} else {
		dfs(0, B, C + A);
	}
	
	if(A >= MAXB - B) {
		dfs(A - MAXB + B, MAXB, C);
	} else {
		dfs(0, B + A, C);
	}
	
	if(B >= MAXA - A) {
		dfs(MAXA, B - MAXA + A, C);
	} else {
		dfs(A + B, 0, C);
	}
	
	if(B >= MAXC - C) {
		dfs(A, B - MAXC + C, MAXC);
	} else {
		dfs(A, 0, B + C);
	}
	
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	
	int A, B, C;
	cin >> MAXA >> MAXB >> MAXC;
	A = B = 0;
	C = MAXC;
	memset(used, 0, sizeof used);
	memset(visit, 0, sizeof visit);
	dfs(0, 0, C);
	int first = true;
	for(int i = 0; i <= MAXN; i++) {
		if(visit[i]) {
			if(first) {
				cout << i;
				first = false;
			} else {
				cout << " " << i;
			}
		}
	}
	cout << endl;
}
