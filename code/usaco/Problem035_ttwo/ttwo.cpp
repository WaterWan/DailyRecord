/**
ID: Wan Zhong
TASK: ttwo
LANG: C++11
**/ 

#include <stdio.h>
const int max_size = 15;
int farmer[max_size][max_size][4];
int cow[max_size][max_size][4];
char forest[max_size][max_size];
int farmer_dir = 0;
int cow_dir = 0;
int farmer_x, farmer_y;
int cow_x, cow_y;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
	freopen("ttwo.in", "r", stdin);
	freopen("ttwo.out", "w", stdout);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			scanf("%c", &forest[i][j]);
			if(forest[i][j] == 'F') {
				farmer_x = i;
				farmer_y = j;
			}
			if(forest[i][j] == 'C') {
				cow_x = i;
				cow_y = j;
			}
		}
	}
}
