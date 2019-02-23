#include <stdio.h>
#include <queue>

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> queue;
	int a;
	long long res = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		queue.push(-a);
		queue.push(-a);
		res += a + queue.top();
		queue.pop();
	}
	printf("%lld", res);
	return 0;
}
