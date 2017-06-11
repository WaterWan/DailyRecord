/**
ID: njuwz151
TASK: wormhole
LANG: C++
*/
#include <iostream>
#include <cstdio>

#define MAXN 12

using namespace std;

typedef struct {
	int x;
	int y;
	int leftId;
} WormHole;

// ×óÈë£¬ÓÒ³ö 
int edge[MAXN][MAXN];
int edge_copy[MAXN][MAXN];
WormHole wormhole[MAXN];

void setUp();

void addEdgeByX(int n);

void showCopy();

void backUp();

int main() {
	freopen("wormhole.in", "r", stdin);
//	freopen("wormhole.out", "w", stdout);
	
	int n;
	cin >> n;
	int x;
	int y;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		wormhole[i].x = x;
		wormhole[i].y = y;
		wormhole[i].leftId = -1;
	}
	
	setUp();
	addEdgeByX(n);
	
	
	backUp();
	showCopy();
}

void setUp() {
	for(int i = 0; i < MAXN; i++) {
		for(int j = 0; j < MAXN; j++) {
			edge[i][j] = 0;
		}
	}
}

void addEdgeByX(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				continue;
			}
			if(wormhole[i].y == wormhole[j].y) {
				if(wormhole[i].x < wormhole[j].x) {
					if(wormhole[j].leftId == -1) {
						wormhole[j].leftId = i;
					} else if(wormhole[i].x > wormhole[wormhole[j].leftId].x){
						wormhole[j].leftId = i;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(wormhole[i].leftId != -1) {
			edge[wormhole[i].leftId][i] = 1;
		}
	}
}

void showCopy() {
	for(int i = 0; i < MAXN; i++) {
		for(int j = 0; j < MAXN; j++) {
			cout << edge_copy[i][j] << " ";
		}
		cout << endl;
	}
}

void backUp() {
	for(int i = 0; i < MAXN; i++) {
		for(int j = 0; j < MAXN; j++) {
			edge_copy[i][j] = edge[i][j];
		}
	}
}
