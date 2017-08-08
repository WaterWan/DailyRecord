/**
ID: Wan Zhong
TASK: maze1
LANG: C++11
**/ 
#include <stdio.h>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int max_w = 45;
const int max_h = 105;
int w, h;
char maze[2 * max_h][2 * max_w];
bool can_visit[max_h][max_w][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; 
int exit_x[2];
int exit_y[2];
int exit_count = 0;
char unused;
int steps1[max_h][max_w];
int steps2[max_h][max_w];
int steps[max_h][max_w];
int main() {
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
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
	memset(steps1, 0, sizeof steps1);
	steps1[exit_x[0]][exit_y[0]] = 1;
	queue<pair<int, int> > q1;
	q1.push(make_pair(exit_x[0], exit_y[0]));
	while(!q1.empty()) {
		auto temp = q1.front();
		for(int i = 0; i < 4; i++) {
			if(temp.first + dx[i] < 0 || temp.first + dx[i] >= h) {
				continue;
			}
			if(temp.second + dy[i] < 0 || temp.second + dy[i] >= w) {
				continue;
			}
			if(!can_visit[temp.first][temp.second][i]) {
				continue;
			}
			if(steps1[temp.first + dx[i]][temp.second + dy[i]]) {
				continue;
			}
			steps1[temp.first + dx[i]][temp.second + dy[i]] = steps1[temp.first][temp.second] + 1;
			q1.push(make_pair(temp.first + dx[i], temp.second + dy[i]));
		}
		q1.pop();
	}
	
	memset(steps2, 0, sizeof steps2);
	steps2[exit_x[1]][exit_y[1]] = 1;
	queue<pair<int, int> > q2;
	q2.push(make_pair(exit_x[1], exit_y[1]));
	while(!q2.empty()) {
		auto temp = q2.front();
		for(int i = 0; i < 4; i++) {
			if(temp.first + dx[i] < 0 || temp.first + dx[i] >= h) {
				continue;
			}
			if(temp.second + dy[i] < 0 || temp.second + dy[i] >= w) {
				continue;
			}
			if(!can_visit[temp.first][temp.second][i]) {
				continue;
			}
			if(steps2[temp.first + dx[i]][temp.second + dy[i]]) {
				continue;
			}
			steps2[temp.first + dx[i]][temp.second + dy[i]] = steps2[temp.first][temp.second] + 1;
			q2.push(make_pair(temp.first + dx[i], temp.second + dy[i]));
		}
		q2.pop();
	}
	
	memset(steps, 0, sizeof steps);
	int max_step = -1;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			steps[i][j] = min(steps1[i][j], steps2[i][j]);
			max_step = max(max_step, steps[i][j]);
		}
	}
	printf("%d\n", max_step);
	return 0;
	
}
