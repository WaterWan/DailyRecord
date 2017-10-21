#include <iostream>
#include <cstdio>
const int maxn = 2e5 + 20;
int n, q, m;
int a[maxn], t[maxn], l[maxn], r[maxn];
using namespace std;

int main() {
	scanf("%d%d%d", &n, &q, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= q; i++) {
		scanf("%d%d%d", &t[i], &l[i], &r[i]);
	}
	while(m--) {
		int x;
		scanf("%d", &x);
		for(int i = q; i > 0; i--) {
			if(l[i] <= x && x <= r[i]) {
				if(t[i] == 2) {
					x = l[i] + r[i] - x;
				} else {
					if(x > l[i]) {
						x--;
					} else {
						x = r[i];
					}
				}
			}
		}
		printf("%d ", a[x]);
	}
}
