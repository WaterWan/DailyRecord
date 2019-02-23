#include <stdio.h>
#include <set>
#include <map>
using namespace std;
int n, m;
const int maxn = 100010;
int a[maxn];
int p[maxn];// 设p[x] = y，假设第x次操作访问了一块主存，那么下一次访问这次主存是在第i次操作
map<int, int> g; // g[i] = l,表示最后一次访问第i号主存是在第l次操作执行的 
set<int> s; // s表示当前可以哪些操作是不需要重新访问cache的 
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		p[i] = n + 1;
		p[g[a[i]]] = i;
		g[a[i]] = i;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(s.find(i) != s.end()) {
			s.erase(i);
			s.insert(p[i]);
		} else {
			cnt++;
			if(s.size() == m) {
				s.erase(--s.end());
			}
			s.insert(p[i]);
		}
	}
	printf("%d", cnt);
	return 0;
}
