#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 30000;
int n, m, k;
int parent[MAX + 10];
int total[MAX + 10];
// total[GetParent(a)]是a所在group的人数
int GetParent(int a) {
	if(parent[a] != a) {
		parent[a] = GetParent(parent[a]);
	}
	return parent[a];
} 

void Merge(int a, int b) {
	int p1 = GetParent(a);
	int p2 = GetParent(b);
	if(p1 == p2) {
		return;
	}
	total[p1] += total[p2];
	parent[p2] = p1;
}

int main() {
	while(true) {
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0) {
			break;
		}
		for(int i = 0; i < n; i++) {
			parent[i] = i;
			total[i] = 1;
		}
		for(int i = 0; i < m; i++) {
			int h, s;
			scanf("%d", &k);
			scanf("%d", &h);
			for(int j = 1; j < k; j++) {
				scanf("%d", &s);
				Merge(h, s);
			}
		}
		printf("%d\n", total[GetParent(0)]);// 不能写parent[0] 
	}
	return 0;
}
