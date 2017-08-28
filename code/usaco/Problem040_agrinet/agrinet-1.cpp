/**
ID: Wan Zhong
TASK: agrinet
LANG: C++11
**/ 
// 目标是用kruskal算法重写 
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 110;
int fa[maxn];
typedef struct Edge{
	int x, y, w;
	Edge(int x = 0, int y = 0, int w = 0): x(x), y(y), w(w){}
	
} Edge;
Edge e[maxn * maxn ];
int n;
int edge_cnt;

void init() {
	cin >> n;
	edge_cnt = 0;
	int weight;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> weight;
			if(i <= j) {
				continue;
			} 
			e[edge_cnt].x = i;
			e[edge_cnt].y = j;
			e[edge_cnt].w = weight;
			edge_cnt++;
		}
	}
}

int get_father(int x) {
	if(x == fa[x]) {
		return x;
	} else {
		return fa[x] = get_father(fa[x]);
	}
}

int cmp(Edge e1, Edge e2) {
	return e1.w < e2.w;
}

int kruskal() {
	sort(e, e + edge_cnt, cmp);
	int cnt = n; // 并查集的个数 
	for(int i = 0; i < maxn; i++) {
		fa[i] = i;
	}
	int ans = 0;
	for(int i = 0; i < edge_cnt; i++) {
		int t1 = get_father(e[i].x);
		int t2 = get_father(e[i].y);
		if(t1 != t2) {
			fa[t1] = t2;
			ans += e[i].w;
			cnt--;
			if(cnt == 1) {
				break;
			}
		}
	}
	return ans;
}

int main() {
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
	init();
	cout << kruskal() << endl;
}

