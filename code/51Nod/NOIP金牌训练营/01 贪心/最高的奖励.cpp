#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int N;
const int maxn = 5e4 + 100;
typedef struct Task{
	int e;
	int w;
	bool operator < (const Task& t) const {
		return w < t.w;
	}
} Task;
Task tasks[maxn];
priority_queue<Task> PQ;
int main() {
	scanf("%d", &N);
	int e;
	int w;
	int maxx = -1;
	for(int i = 0; i < N; i++) {
		scanf("%d%d", &e, &w);
		tasks[i].e = e;
		tasks[i].w = w;
		maxx = max(maxx, e);
	}
	sort(tasks, tasks + N, [](Task t1, Task t2) {
		return t1.e > t2.e;
	});
	int ptr = 0;
	long long res = 0LL;
	for(int i = maxx; i; i--) {
		while(true) {
			// 在第i天之前的项目 
			if(tasks[ptr].e < i) {
				break;
				// 刚好是第i天的项目 
			} else if(tasks[ptr].e == i) {
				PQ.push(tasks[ptr++]);
			} 
		}
		if(!PQ.empty()) {
			Task temp = PQ.top();
			PQ.pop();
			res += temp.w;
		} 
	}
	printf("%lld", res);
	return 0;
}
