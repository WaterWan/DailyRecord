#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 1010;
int a[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		sum += 1LL * (n - i) * a[i];
	}
	printf("%lld", sum);
	return 0;
}
