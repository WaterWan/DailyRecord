/**
ID: Wan Zhong
TASK: cowtour
LANG: C++11
**/ 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
const int MAXN = 155;
const int INF = 0x3f3f3f3f;
int N;
int X[MAXN], Y[MAXN];
double point_dis[MAXN][MAXN], dis[MAXN][MAXN], farthest[MAXN];
bool G[MAXN][MAXN];
 
double get_dis(int x1, int y1, int x2, int y2) { 
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
void floyd(int n) {
    for (int k = 0; k < n; k++) {
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
 
int main() {
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
    	scanf("%d%d\n", &X[i], &Y[i]);
	} 
    for (int i = 0; i < N; i++, getchar()) {
    	for (int j = 0; j < N; j++) {
    		G[i][j] = getchar() - '0'; 
		}
	}

 
    for (int i = 0; i < N; i++) {
    	for (int j = 0 ; j < N; j++) {
            if (i == j) {
				point_dis[i][j] = dis[i][j] = 0; 
				continue;
			}
            point_dis[i][j] = get_dis(X[i], Y[i], X[j], Y[j]);
            if (G[i][j]) {
            	dis[i][j] = point_dis[i][j];
			} else {
				dis[i][j] = INF;	
			}
        }
	}

    floyd(N);
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		if (dis[i][j] < INF) {
            	farthest[i] = max(farthest[i], dis[i][j]);
			}
		}
	}

			
    double ans = INF;
    for (int i = 0; i < N; i++) {
    	for (int j = i + 1; j < N; j++) if (!G[i][j] && dis[i][j] == INF) {
            double nowmax = farthest[i] + point_dis[i][j] + farthest[j];
            if (nowmax >= ans) {
            	continue;
			}
            for (int k = 0; k < N; k++) {
            	nowmax = max(nowmax, farthest[k]);
			}
            ans = nowmax;
        }
	}

    printf("%.6lf\n", ans);
    return 0;
}
