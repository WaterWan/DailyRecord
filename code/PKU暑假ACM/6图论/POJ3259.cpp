#include <iostream>
#include <vector>

using namespace std;

int F, N, M, W;

const int INF = 1 << 30;
struct Edge {
	int s, e, w;
	Edge(int ss, int ee, int ww): s(ss), e(ee), w(ww) {}
	Edge(){}	
};  
vector<Edge> edges; // 所有的边
int dist[1000];

int Bellman_ford(int v) {
	for(int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	dist[v] = 0;
	for(int k = 1; k < N; k++) { // 经过不超过k条边 
		for(int i = 0; i < edges.size(); i++) {
			int s = edges[i].s;
			int e = edges[i].e;
			if(dist[s] + edges[i].w < dist[e]) {
				dist[e] = dist[s] + edges[i].w;
			}
		}
	}
	for(int i = 0; i < edges.size(); i++) {
		int s = edges[i].s;
		int e = edges[i].e;
		if(dist[s] + edges[i].w < dist[e]) {
			return true;
		}
	}
	return false;
} 

int main() {
	cin >> F;
	while(F--) {
		edges.clear();
		cin >> N >> M >> W;
		for(int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back(Edge(s, e, t)); // 双向边等于两条边 
			edges.push_back(Edge(e, s, t));
		}
		for(int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edges.push_back((Edge(s, e, -t)));
		}
		if(Bellman_ford(1)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
