/**
ID: Wan Zhong
TASK: ttwo
LANG: C++11
**/ 
#include <stdio.h>
#include <cstring>

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
	memset(farmer, 0, sizeof farmer);
	memset(cow, 0, sizeof cow);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 11; j++) {
			scanf("%c", &forest[i][j]);
			if(forest[i][j] == 'F') {
				farmer_x = i;
				farmer_y = j;
				farmer[i][j][0] = 1;
			}
			if(forest[i][j] == 'C') {
				cow_x = i;
				cow_y = j;
				cow[i][j][0] = 1;
			}
		}
	}
	int step_count = 0;

	while(!(farmer_x == cow_x && farmer_y == cow_y)) {
		if(farmer_x + dx[farmer_dir] < 0 || farmer_y + dy[farmer_dir] < 0
		|| farmer_x + dx[farmer_dir] > 9 || farmer_y + dy[farmer_dir] > 9
		|| forest[farmer_x + dx[farmer_dir]][farmer_y + dy[farmer_dir]] == '*') {
			farmer_dir = (farmer_dir + 1) % 4;
		} else {
			farmer_x += dx[farmer_dir];
			farmer_y += dy[farmer_dir];
		}
		if(cow_x + dx[cow_dir] < 0 || cow_y + dy[cow_dir] < 0
		|| cow_x + dx[cow_dir] > 9 || cow_y + dy[cow_dir] > 9
		|| forest[cow_x + dx[cow_dir]][cow_y + dy[cow_dir]] == '*') {
			cow_dir = (cow_dir + 1) % 4;
		} else {
			cow_x += dx[cow_dir];
			cow_y += dy[cow_dir];
		}
		step_count++;
		if(!(step_count > 250000)) {
			farmer[farmer_x][farmer_y][farmer_dir] = step_count;
			cow[cow_x][cow_y][cow_dir] = step_count; 
		} else {
			printf("0\n");
			return 0;
		}
	}
	printf("%d\n", step_count);
	return 0;
}
