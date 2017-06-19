/**
ID: njuwz151
TASK: frac1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 165;

int n;

typedef struct {
	int x;
	int y;
} Frac;

Frac frac[maxn*maxn];
int cmp(Frac a, Frac b);
int gcd(int a, int b);

int main() {
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	
	cin >> n;	
	int count = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
//			cout << i << "   " << j << "    " << gcd(i, j) << endl;
			if(gcd(i, j) == 1) {
				frac[count].x = j;
				frac[count].y = i;
				count++;
			}
		}
	}
	
	sort(frac, frac + count, cmp);
	for(int i = 0; i < count; i++) {
		cout << frac[i].x << "/" << frac[i].y << endl;
	}
}

int cmp(Frac a, Frac b) {
	return a.x * b.y < b.x * a.y;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
