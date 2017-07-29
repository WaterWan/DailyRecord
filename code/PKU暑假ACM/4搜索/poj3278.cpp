#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;

const int maxn = 100000;
int visited[maxn + 10];// 判重 

struct Step{
	int x; // 位置
	int steps; // 到达x需要的步数
	Step(int xx, int s) : x(xx), steps(s) {
		
	}
};

queue<Step> q; // open表 

int main() {
	cin >> N >> K;
	memset(visited, 0, sizeof visited);
	q.push(Step(N, 0));
	visited[N] = 1;
	while(!q.empty()) {
		Step s = q.front();
		if(s.x == K) {
			cout << s.steps << endl;
			return 0;
		} else {
			if(s.x - 1 >= 0 && !visited[s.x - 1]) {
				q.push(Step(s.x - 1, s.steps + 1));
				visited[s.x - 1] = 1;
			} 
			if(s.x + 1 <= maxn && !visited[s.x + 1]) {
				q.push(Step(s.x + 1, s.steps + 1));
				visited[s.x + 1] = 1; 
			}
			if(s.x * 2 <= maxn && !visited[s.x * 2]) {
				q.push(Step(s.x * 2, s.steps + 1));
				visited[s.x * 2] = 1;
			}
			q.pop();
		}
	} 
	return 0;
}
