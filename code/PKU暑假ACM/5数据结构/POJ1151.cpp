#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

double y[210];

struct CNode {
	int L, R;
	CNode *pLeft, *pRight;
	double len; // 当前，本区间上有多长的部分是落在那些矩形中的
	int Covers; // 本区间当前被多少矩形完全包含 
};
CNode Tree[1000];

struct CLine {
	double x, y1, y2;
	bool bLeft; // 是否是矩形的左边 
} lines[210];

int nNodeCount = 0;

bool operator < (const CLine & l1, const CLine & l2) {
	return l1.x < l2.x;
}

template <typename F, typename T>
F bin_search(F s, F e, T val) { // 在区间[s, e)中查找val，找不到就返回e 
	F L = s;
	F R = e - 1;
	while(L <= R) {
		F mid = L + (R - L) / 2;
		if(!(*mid < val || val < *mid)) {
			return mid;
		} else if(val < *mid) {
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	return e;
}
int Mid(CNode *pRoot) {
	return (pRoot->L + pRoot->R) >> 1;
}

void Insert(CNode *pRoot, int L, int R) {
	// 在区间pRoot插入矩形左边的一部分或全部，该左边的一部分或全部覆盖了区间[L, R]
	 if(pRoot->L == L && pRoot->R == R) {
	 	pRoot->len = y[R+1] - y[L];
	 	pRoot->Covers++;
	 	return;
	 }
	 if(R <= Mid(pRoot)) {
		Insert(pRoot->pLeft, L, R);
	 } else if(L >= Mid(pRoot) + 1) {
	 	Insert(pRoot->pRight, L, R);
	 } else {
	 	Insert(pRoot->pLeft, L, Mid(pRoot));
	 	Insert(pRoot->pRight, Mid(pRoot) + 1, R);
	 }
	 if(pRoot->Covers == 0) {
	 	// 如果不为0，则说明本区间当前仍然被某个矩形完全包含，则不能更新len 
	 	pRoot->len = pRoot->pLeft->len + pRoot->pRight->len;
	 }
}

void Delete(CNode *pRoot, int L, int R) {
	// 在区间pRoot删除矩形右边的一部分或全部，该矩形的右边的一部分或全部覆盖了区间[L,R]
	if(pRoot->L == L && pRoot->R == R) {
		pRoot->Covers--;
		if(pRoot->Covers == 0) {
			if(pRoot->L == pRoot->R) {
				pRoot->len = 0;
			} else {
				pRoot->len = pRoot->pLeft->len + pRoot->pRight->len;
			}
		}
		return;
	} 
	if(R <= Mid(pRoot)) {
		Delete(pRoot->pLeft, L, R);
	} else if(L >= Mid(pRoot) + 1) {
		Delete(pRoot->pRight, L, R);
	} else {
		Delete(pRoot->pLeft, L, Mid(pRoot));
		Delete(pRoot->pRight, Mid(pRoot) + 1, R);
	}
	if(pRoot->Covers == 0) {
		// 如果不为0，则说明本区间当前仍然被某个矩形完全包含，则不能更新len 
	 	pRoot->len = pRoot->pLeft->len + pRoot->pRight->len;	
	}
}

void BuildTree(CNode *pRoot, int L, int R) {
	pRoot->L = L;
	pRoot->R = R;
	pRoot->Covers = 0;
	pRoot->len = 0;
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

int main() {
	freopen("1151.in", "r", stdin);
	int n;
	int i, j, k;
	double x1, y1, x2, y2;
	int yc, lc;
	int nCount = 0;
	int t = 0;
	while(true) {
//		cin >> n;
		scanf("%d", &n); 
		if(n == 0) {
			break;
		}
		t++;
		yc = lc = 0;
		for(i = 0; i < n; i++) {
//			cin >> x1 >> y1 >> x2 >> y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			y[yc++] = y1;
			y[yc++] = y2;
			lines[lc].x = x1;
			lines[lc].y1 = y1;
			lines[lc].y2 = y2;
			lines[lc].bLeft = true;
			lc++;
			lines[lc].x = x2;
			lines[lc].y1 = y1;
			lines[lc].y2 = y2;
			lines[lc].bLeft = false;
			lc++;
		}
		sort(y, y + yc);
		yc = unique(y, y + yc) - y;
		nNodeCount = 0;
		// yc是横线的条数，yc-1是纵向区间的个数，这些区间从0开始编号
		// 那么最后一个区间的编号就是yc - 1 - 1
		BuildTree(Tree, 0, yc - 1 - 1);
		sort(lines, lines + lc);
		double Area = 0;
		for(i = 0; i < lc - 1; i++) {
			int L = bin_search(y, y + yc, lines[i].y1) - y;
			int R = bin_search(y, y + yc, lines[i].y2) - y;
			if(lines[i].bLeft) {
				Insert(Tree, L, R - 1);
			} else {
				Delete(Tree, L ,R - 1);
			}
			Area += Tree[0].len * (lines[i + 1].x - lines[i].x);
		} 
		printf("Test case #%d\n", t);
		printf("Total explored area: %.2lf\n", Area);
		printf("\n");
	} 
	return 0;
}
