/**
ID: Wan Zhong
TASK: maze1
LANG: C++11
**/ 
#include <stdio.h>
#include <cstring>
const int max_w = 45;
const int max_h = 105;
int w, h;
char maze[2 * max_w][2 * max_h];
bool can_visit[max_w][max_h][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; 
int exit_x[2];
int exit_y[2];
int exit_count = 0;
char unused;
int main() {
	freopen("maze1.in", "r", stdin);
//	freopen("maze1.out", "w", stdout);
	scanf("%d%d", &w, &h);
	scanf("%c", &unused);
	for(int i = 0; i < 2 * h + 2; i++) {
		for(int j = 0; j < 2 * w + 2; j++) {
			scanf("%c", &maze[i][j]);
		}
	}

	memset(can_visit, 0, sizeof can_visit);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			int mid_x = 2 * i + 1;
			int mid_y = 2 * j + 1;
			for(int k = 0; k < 4; k++) {
				if(maze[mid_x + dx[k]][mid_y + dy[k]] == ' ') {
					can_visit[i][j][k] = true;
				}
			}
		}
	}

	for(int i = 0; i < w; i++) {
		if(maze[0][2 * i + 1] == ' ') {
			exit_x[exit_count] = 0;
			exit_y[exit_count] = i;
			exit_count++;
		}
	}
	for(int i = 0; i < w; i++) {
		if(maze[2 * h][2 * i + 1] == ' ') {
			exit_x[exit_count] = h - 1;
			exit_y[exit_count] = i;
			exit_count++;
		}
	}
	for(int i = 0; i < h; i++) {
		if(maze[2 * i + 1][0] == ' ') {
			exit_x[exit_count] = i;
			exit_y[exit_count] = 0;
			exit_count++;
		}
	}
	for(int i = 0; i < h; i++) {
		if(maze[2 * i + 1][2 * w] == ' ') {
			exit_x[exit_count] = i;
			exit_y[exit_count] = w - 1;
			exit_count++;
		}
	}

	
}
