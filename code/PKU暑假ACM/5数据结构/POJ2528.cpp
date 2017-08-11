#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n;

struct CPost {
	int L, R;
};

CPost posters[10100];
int x[20200]; // 存放所有海报的端点瓷砖编号 
int my_hash[10000010]; // my_hash[i]表示瓷砖i所处的离散化后的区间编号
struct CNode {
	int L, R;
	bool bCovered; // 区间[L, R]是否已经被*完全*覆盖 
	CNode *pLeft, *pRight; 
}; 
CNode Tree[1000000];
int nNodeCount = 0;

int Mid(CNode *pRoot) {
	return (pRoot->L + pRoot->R) / 2;
}

void BuildTree(CNode *pRoot, int L, int R) {
	pRoot->L = L;
	pRoot->R = R;
	pRoot->bCovered = false;
	if(L == R) {
		return;
	}
	nNodeCount++;
	pRoot->pLeft = Tree + nNodeCount;
	nNodeCount++;
	pRoot->pRight = Tree + nNodeCount;
	BuildTree(pRoot->pLeft, L, (L + R) / 2);
	BuildTree(pRoot->pRight, (L + R) / 2 + 1, R);
}

bool Post(CNode *pRoot, int L, int R) {
	// 插入一张正好覆盖区间[L, R]的海报，返回true则说明区间[L, R]是部分或者全部可见的
	if(pRoot->bCovered) {
		return false;
	} 
	if(pRoot->L == L && pRoot->R == R) {
		pRoot->bCovered = true;
		return true;
	}
	bool bResult;
	if(R <= Mid(pRoot)) {
		bResult = Post(pRoot->pLeft, L, R);
	} else if(L >= Mid(pRoot) + 1) {
		bResult = Post(pRoot->pRight, L, R);
	} else {
		bool b1 = Post(pRoot->pLeft, L, Mid(pRoot));
		bool b2 = Post(pRoot->pRight, Mid(pRoot) + 1, R);
		bResult = b1 || b2;
	}
	if(pRoot->pLeft->bCovered && pRoot->pRight->bCovered) {
		pRoot->bCovered = true;
	}
	return bResult;
}

int main() {
	int t;
	int i, j, k;
	scanf("%d", &t);
	int nCaseNo = 0;
	while(t--) {
		nCaseNo++;
		scanf("%d", &n);
		int nCount = 0;
		for(i = 0; i < n; i++) {
			scanf("%d%d", &posters[i].L, &posters[i].R);
			x[nCount++] = posters[i].L;
			x[nCount++] = posters[i].R;
		}
		sort(x, x + nCount);
		nCount = unique(x, x + nCount) - x; // 去掉重复元素
		// 下面离散化 
		int nIntervalNo = 0;
		for(i = 0; i < nCount; i++) {
			my_hash[x[i]] = nIntervalNo;
			if(i < nCount - 1) {
				if(x[i+1] - x[i] == 1) {
					nIntervalNo++;
				} else {
					nIntervalNo += 2;
				}
			}
		} 
		
		BuildTree(Tree, 0, nIntervalNo);
		int nSum = 0;
		for(i = n - 1; i >= 0; i--) {
			if(Post(Tree, my_hash[posters[i].L], my_hash[posters[i].R])) {
				nSum++;
			}
		}
		printf("%d\n", nSum);
	}
	return 0;
}
