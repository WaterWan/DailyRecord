# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <cstring>

using namespace std;

struct CNode {
	int k; // ����ߵ��յ�
	int w; // Ȩֵ����ǰk��Դ��ľ��� 
}; 

bool operator < (const CNode &d1, const CNode &d2) {
	return d1.w > d2.w; // priority_queue���ǽ�����Ԫ�س��� 
}
priority_queue<CNode> pq;
bool bUsed[30010] = {0};

vector< vector<CNode> > v; // v������ͼ���ڽӱ�
const unsigned int INFINITE = 100000000;

int main() {
	int N, M, a, b, c;
	int i, j, k;
	CNode p;
	scanf("%d%d", &N, &M);
	v.clear();
	v.resize(N+1);
	memset(bUsed, 0, sizeof bUsed);
	for(i = 1; i<= M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		p.k = b;
		p.w = c;
		v[a].push_back(p);
	}
	p.k = 1; // Դ����1�ŵ� 
	p.w = 0; // 1�ŵ㵽�Լ��ľ�����0 
	pq.push(p);
	while(!pq.empty()) {
		p = pq.top();
		pq.pop();
		if(bUsed[p.k]) { // �Ѿ���������· 
			continue;
		}
		bUsed[p.k] = true;
		if(p.k == N) { // ֻҪ����1-N�����· 
			break;
		}
		for(i = 0, j = v[p.k].size(); i < j; i++) {
			CNode q;
			q.k = v[p.k][i].k;
			if(bUsed[q.k]) {
				continue;
			}
			q.w = p.w + v[p.k][i].w;
			pq.push(q); // ���������Ѿ���q.k��Ҳû��ϵ 
		}
	}
	printf("%d\n", p.w);
	return 0;
} 
