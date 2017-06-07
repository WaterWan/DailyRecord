/**
ID: njuwz151
TASK: milk
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 5000

using namespace std;

typedef struct {
	int p;
	int a;
}MilkMan;

bool milkmanCmp(MilkMan m1, MilkMan m2);

int main() {
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
	int n;
	int m;
	int p;
	int a;
	int total = 0;
	MilkMan milkman[MAXN];
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> p >> a;
		milkman[i].a = a;
		milkman[i].p = p;
	}
	/**
	*从价格由低到高选择
	*直到买满所有的 
	**/ 
	sort(milkman, milkman + m, milkmanCmp);
	for(int i = 0; i < m; i++) {
		if(milkman[i].a < n) {
			n -= milkman[i].a;
			total += milkman[i].p * milkman[i].a;
		} else {
			total += n * milkman[i].p;
			n = 0;
		}
		if(n == 0) {
			break;
		}
	}
	cout << total << endl;
}

bool milkmanCmp(MilkMan m1, MilkMan m2) {
	return m1.p < m2.p;
}
