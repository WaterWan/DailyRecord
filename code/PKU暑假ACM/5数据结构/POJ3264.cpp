#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int maxV = -INF;
int minV = INF;

struct Node {
	int L, R;
	int maxV, minV;
	int Mid() {
		return (L + R) / 2;
	}
};
Node tree[800010];

void BuildTree(int root, int L, int R) {
	tree[root].L = L;
	tree[root].R = R;
	tree[root].minV = INF;
	tree[root].maxV = -INF;
	if(L != R) {
		BuildTree(2 * root + 1, L, (L + R) / 2);
		BuildTree(2 * root + 2, (L + R) / 2 + 1, R);
	}
}

// 将第i个数，值为v，插入线段树 
void Insert(int root, int i, int v) {
	if(tree[root].L == tree[root].R) {
		tree[root].minV = tree[root].maxV = v;
		return;
	}
	tree[root].minV = min(tree[root].minV, v);
	tree[root].maxV = max(tree[root].maxV, v);
	if(i <= tree[root].Mid()) {
		Insert(2 * root + 1, i, v);
	} else {
		Insert(2 * root + 2, i, v);
	}
}


// 查询区间[s, e]中的最小值和最大值，如果更优就记在全局变量里 
void Query(int root, int s, int e) {
	if(tree[root].minV >= minV && tree[root].maxV <= maxV) {
		return;
	}
	if(tree[root].L == s && tree[root].R == e) {
		minV = min(minV, tree[root].minV);
		maxV = max(maxV, tree[root].maxV);
		return;
	}
	if(e <= tree[root].Mid()) {
		Query(2 * root + 1, s, e);
	} else if(s > tree[root].Mid()) {
		Query(2 * root + 2, s, e);
	} else {
		Query(2 * root + 1, s, tree[root].Mid());
		Query(2 * root + 2, tree[root].Mid() + 1, e);
	}
}

int main() {
	int n, q, h;
	int i, j, k;
	scanf("%d%d", &n, &q);
	BuildTree(0, 1, n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &h);
		Insert(0, i, h);
	}
	for(i = 0; i < q; i++) {
		int s, e;
		scanf("%d%d", &s, &e);
		minV = INF;
		maxV = -INF;
		Query(0, s, e);
		printf("%d\n", maxV - minV);
	}
	return 0;
}
