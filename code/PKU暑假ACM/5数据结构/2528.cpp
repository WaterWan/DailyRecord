#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int n;

struct CPost {
	int L, R;
};

CPost posters[10100];
int x[20200]; // ������к����Ķ˵��ש��� 
int hash[10000010]; // hash[i]��ʾ��שi��������ɢ�����������
struct CNode {
	int L, R;
	bool bCovered; // ����[L, R]�Ƿ��Ѿ���*��ȫ*���� 
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
