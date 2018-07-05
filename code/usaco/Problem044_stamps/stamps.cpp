/**
ID: Wan Zhong
TASK: stamps
LANG: C++11
**/
#include <stdio.h>
#include <algorithm>
using namespace std;
int K, N;
const int maxn = 55;
const int maxk = 210;
int a[maxn];
const int max_num = 200 * 10000 + 100;
int min_cost[max_num];
int min(int x, int y) {
    if(x < y) {
        return x;
    } else {
        return y;
    }
}
int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
    scanf("%d%d", &K, &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + N);
    const int max_bound = a[N - 1] * K + 10;
    // 遍历所有可能的数字 
	for(int i = 1; i < max_bound; i++) {
		// 遍历所有的邮票 
		for(int j = 0; j < N; j++) {
			int num = i - a[j];
			// 是否存在一种情况，是在原来的基础上，加了一张j号邮票得来的 
			if(num >= 0) {
				if(min_cost[i] == 0 || min_cost[i] > min_cost[num] + 1) {
					min_cost[i] = min_cost[num] + 1;
				}
			}
		}
		if(!min_cost[i] || min_cost[i] > K) {
			printf("%d\n", i - 1);
			break;
		}
	}
    return 0;
}
