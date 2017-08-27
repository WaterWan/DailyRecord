/**
ID: Wan Zhong
TASK: agrinet
LANG: C++11
**/ 
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
int matrix[maxn][maxn];
bool visited[maxn];
int n;

int get_unvisited() {
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			return i;
		}
	}
	return -1;
}
int main() {
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	cin >> n;
	memset(visited, 0, sizeof visited);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int dis = 0;
	visited[0] = true;
	int next = get_unvisited();
	while(next != -1) {
		int min_dis = inf;
		int min_id = -1;
		for(int i = 0; i < n; i++) {
			if(visited[i]) {
				for(int j = 0; j < n; j++) {
					if(!visited[j]) {
						if(matrix[i][j] < min_dis) {
							min_dis = matrix[i][j];
							min_id = j;
						}
					}
				}
			}
		}
		dis += min_dis;
		visited[min_id] = true;
		next = get_unvisited();
	}
	cout << dis << endl;
}

