#include <iostream>
#include <set>
using namespace std;
const int maxn = 1e5 + 10;
int L[maxn], R[maxn];
long long m[maxn];
set<pair<long long, int> >s;

void insert(int x) {
	s.insert(make_pair(m[x], x));
}

void erase(int x) {
	s.erase(make_pair(m[x], x));
}

void del(int x) {
	erase(x);
	R[L[x]] = R[x];
	L[R[x]] = L[x];
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &m[i]);
		insert(i);
		L[(i + 1) % n] = i;
		R[i] = (i + 1) % n;
	}
	long long ans = 0;
	for(int i = 0; i < n / 3; i++) {
		int j = s.rbegin()->second;
		long long a = m[L[j]];
		long long b = m[j];
		long long c = m[R[j]];
		ans += b;
		del(L[j]);
		del(R[j]);
		erase(j);
		m[j] = a + c - b;
		insert(j);
	}
	printf("%lld", ans);
}
