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
int hash[10000010]; // hash[i]表示瓷砖i所处的离散化后的区间编号
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
	pRoot->pRight = Tree + nNodeCOunt;
	BUildTree(pRoot->pLeft, L, (L + R) / 2);
	BuildTree(pRoot->pRight, (L + R) / 2 + 1, R);
}
