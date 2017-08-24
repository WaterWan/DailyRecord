/**
ID: Wan Zhong
TASK: comehome
LANG: C++11
**/ 
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;
 
bool flag[52] = {};
int a[52][52], dist[52];
int p;
const int inf = 0x3f3f3f3f;
int main() {
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	memset(a, inf, sizeof a);
	scanf("%d", &p);

	for (int i = 0;i < p; i++) {
		char u, v;
		int w;
		scanf("%*c%c %c%d", &u, &v, &w); // ³Ôµô»»ÐÐ·û 
		u = islower(u) ? u-'a' : u-'A'+26;
		v = islower(v) ? v-'a' : v-'A'+26;
		if (w < a[u][v]) {
			a[u][v] = w;
			a[v][u] = w;
		} 
	}
	copy(a[51], a[51]+52, dist);
	while(true) {
		int min_dist = inf, u;
		for (int i = 0; i < 51; i++) {
			if (!flag[i] && dist[i] < min_dist) {
				min_dist = dist[i];
				u = i;
			}
		}
		if (u >= 26) {
			printf("%c %d\n", u-26+'A', min_dist);
			return 0;
		} 
		flag[u] = true;
		for (int i = 0; i < 51; ++i) {
			if (!flag[i] && dist[u]+a[u][i] < dist[i]) {
				dist[i] = dist[u]+a[u][i];
			}
		}

	}
}
