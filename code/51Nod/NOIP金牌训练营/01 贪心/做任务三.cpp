#include <stdio.h>
#include <queue>
#include <algorithm>
typedef struct {
	int s;
	int e;
} Task;
const int maxn = 100010;
Task tasks[maxn];
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		priority_queue<int> queue;
		int cnt = 0;
		int s, e;
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &s, &e);
			tasks[i] = {s, e};
		}
		sort(tasks, tasks + n, [](Task t1, Task t2) {
			if(t1.s != t2.s) {
				return t1.s < t2.s;
			}	
			return t1.e < t2.e;
		});
		for(int i = 0; i < n; i++) {
			if(queue.size() > 0 && tasks[i].s >= -queue.top()) {
				queue.pop();
				queue.push(-tasks[i].e);
			} else {
				cnt++;
				queue.push(-tasks[i].e);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
