/**
ID: njuwz151
TASK: castle
LANG: C++
**/
#include <bits/stdc++.h>

#define MAXN 55

using namespace std;

int wall[MAXN][MAXN][5] = {0};
bool visit[MAXN][MAXN] = {false};
int m, n;
int color = 1;
int roomSize[MAXN * MAXN] = {0};
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void flood_fill(int x, int y);

int main() {
	freopen("castle.in", "r", stdin);
//	freopen("castle.out", "w", stdout);

	cin >> m >> n;
	int t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> t;
			/**
			1: wall to the west
			2: wall to the north
			4: wall to the east
			8: wall to the south
			*/
			for(int k = 0; k < 4; k++) {
//				cout << i << " " << j << " " << k << " " << t%2 << endl;
				wall[i][j][k] = t%2;
				t /= 2;
			}
			wall[i][j][4] = 0;
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!visit[i][j]) {
				roomSize[color] = 0;
				flood_fill(i, j);
				color++;
			}
		}
	}
	int max = 0;
	for(int i = 1; i < color; i++) {
		if(roomSize[i] > max) {
			max = roomSize[i];
		}
//		cout << roomSize[i] << " ";
	}
	cout << color - 1 << endl;
	cout << max << endl;
} 

void flood_fill(int x, int y) {
	visit[x][y] = true;
	roomSize[color]++;
	wall[x][y][4] = color;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0) {
			continue;
		}
		if(nx >= n || ny >= m) {
			continue;
		}
		if(visit[nx][ny]) {
			continue;
		}
		if(wall[x][y][i]) {
			continue;
		}
		flood_fill(nx, ny);
	}

}

