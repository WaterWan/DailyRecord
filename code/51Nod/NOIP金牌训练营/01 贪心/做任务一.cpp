#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 100010;
typedef struct {
	int s;
	int e;
} Task;
Task tasks[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int s, e;
		for(int i = 0; i < n; i++) {
			scanf("%d%d", &s, &e);
			tasks[i] = {s, e};
		}
		sort(tasks, tasks + n, [](Task t1, Task t2){
			if(t1.s != t2.s) {
				return t1.s < t2.s;
			}
			return t1.e < t2.e;
		});
		int cnt = 0;
		int end = 0;
		for(int i = 0; i < n; i++) {
			if(tasks[i].s >= end) {
				end = tasks[i].e;
				cnt++;
			} else if(tasks[i].e < end){
				end = tasks[i].e;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
