#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100005;
const int maxm = 1005;
#define INF 0x3f3f3f3f
int n, m;
int a[maxn], b[maxn];
int k[maxm], p[maxm];
int dp[11][maxm];
int maxb;
int maxp;
int maxa[13];

void get_input();
void init();
void compute();

int main() {
//	freopen("C.in", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		get_input();
		compute();
	}
}

void get_input() {
	maxb = -1;
	maxp = -1;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		maxb = max(maxb, b[i]);
		maxa[b[i]] = max(maxa[b[i]], a[i]);
	}
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &k[i], &p[i]);
		maxp = max(maxp, p[i]);
	}
}

void init() {
	memset(dp, INF, sizeof dp);
	for (int i = 0; i <= 10; i++){
		dp[i][0] = 0;
	}
	memset(maxa, 0, sizeof maxa);
}

void compute() {
	if(maxb >= maxp) {
		printf("-1\n");
		return;
	}
	for(int d = 0; d < 11; d++) {
		for(int i = 0; i < m; i++) {
			int damage = p[i] - d;
			if(damage <= 0) {
				continue;
			}
			int cost = k[i];
			for(int j = 0; j <= maxa[d]; j++) {
				int left = j - damage;
				if(left >= 0) {
					dp[d][j] = min(dp[d][j], dp[d][left] + cost);
				} else {
					dp[d][j] = min(dp[d][j], cost);
				}
			}
		}
	}
	long long total_cost = 0;
	for(int i = 0; i < n; i++) {
		total_cost += dp[b[i]][a[i]];
	}
	printf("%I64d\n", total_cost);
}
