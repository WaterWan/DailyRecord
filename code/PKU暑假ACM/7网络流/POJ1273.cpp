#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int G[300][300];
int Prev[300]; // 路径上每个节点的前驱节点
bool Visited[300];
int n, m; // m是顶点数目，顶点编号从1开始 1是源，m是汇，n是边数
unsigned Augment() {
	int v;
	int i;
	deque<int> q;
	memset(Prev, 0, sizeof Prev);
	memset(Visited, 0, sizeof Visited);
	Prev[1] = 0;
	Visited[1] = 1;
	q.push_back(1);
	bool bFindPath = false;
	// 利用bfs孕照一条源到汇的可行路径
	while(!q.empty()) {
		v = q.front();
		q.pop_front();
		for(i = 1; i <= m; i++) {
			if(G[v][i] > 0 && Visited[i] == 0) {
				// 必须是依然有容量的边，才可以走
				Prev[i] = v;
				Visited[i] = 1;
				if(i == m) {
					bFindPath = true;
					q.clear();
					break;
				} else {
					q.push_back(i);
				}
			}
		}
	} 
	if(!bFindPath) {
		return 0;
	}
	int nMinFlow = 999999999;
	v = m;
	// 寻找源到汇路径上容量最小的边，其容量就是此次增加的总流量
	while(Prev[v]) {
		nMinFlow = min(nMinFlow, G[Prev[v]][v]);
		v = Prev[v];
	} 
	// 沿此路径添加反向边，同时修改路径上每条边的容量
	v = m;
	while(Prev[v]) {
		G[Prev[v]][v] -= nMinFlow;
		G[v][Prev[v]] += nMinFlow;
		v = Prev[v];
	} 
	return nMinFlow;
} 

int main() {
	while(cin >> n >> m) {
		// m是顶点数目，顶点编号从1开始
		int i, j, k;
		int s, e, c;
		memset(G, 0, sizeof G);
		for(i = 0; i < n; i++) {
			cin >> s >> e >> c;
			G[s][e] += c; // 两点之间可能有多条边 
		} 
		unsigned int MaxFlow = 0;
		unsigned int aug;
		while(aug = Augment()) {
			MaxFlow += aug;
		}
		cout << MaxFlow << endl;
	}
	return 0;
}
