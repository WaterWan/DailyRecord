#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int G[300][300];
int Prev[300]; // ·����ÿ���ڵ��ǰ���ڵ�
bool Visited[300];
int n, m; // m�Ƕ�����Ŀ�������Ŵ�1��ʼ 1��Դ��m�ǻ㣬n�Ǳ���
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
	// ����bfs����һ��Դ����Ŀ���·��
	while(!q.empty()) {
		v = q.front();
		q.pop_front();
		for(i = 1; i <= m; i++) {
			if(G[v][i] > 0 && Visited[i] == 0) {
				// ��������Ȼ�������ıߣ��ſ�����
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
	// Ѱ��Դ����·����������С�ıߣ����������Ǵ˴����ӵ�������
	while(Prev[v]) {
		nMinFlow = min(nMinFlow, G[Prev[v]][v]);
		v = Prev[v];
	} 
	// �ش�·����ӷ���ߣ�ͬʱ�޸�·����ÿ���ߵ�����
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
		// m�Ƕ�����Ŀ�������Ŵ�1��ʼ
		int i, j, k;
		int s, e, c;
		memset(G, 0, sizeof G);
		for(i = 0; i < n; i++) {
			cin >> s >> e >> c;
			G[s][e] += c; // ����֮������ж����� 
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
