#include <stdio.h>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int n, m, p;
const int maxn = 100010;
pair<int, int> a[maxn];
pair<int, int> b[maxn];
multiset<int> s;
int main() {
	scanf("%d%d", &n, &m);
	int x, y;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[i] = {-y, x};
	}
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		b[i] = {-y, x};
	}
	sort(a, a + n);
	sort(b, b + m);
	long long res = 0;
	for(int i = 0; i < n; i++) {
		while(p < m && -a[i].first <= -b[p].first) {
			s.insert(b[p++].second);
		}
		auto it = s.lower_bound(a[i].second);
		if(it == s.end()) {
			res = -1;
			break;	
		} else {
			res += *it;
			s.erase(it);
		}
	}
	printf("%lld", res);
	return 0;
}
