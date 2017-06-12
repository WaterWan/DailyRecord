/**
ID: njuwz151
TASK: skidesign
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 1000

using namespace std;

int main() {
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
	
	int height[MAXN];
	int costs[101];
	
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> height[i];
	}
	
//	sort(height, height + N);
	
	for(int i = 0; i <= 100; i++) {
		int goalHeight = i;
		int cost = 0;
		for(int j = 0; j < N; j++) {
			if(height[j] > goalHeight) {
				cost += (height[j] - goalHeight) * (height[j] - goalHeight);
			} else if(height[j] < goalHeight - 17) {
				cost += (height[j] - goalHeight + 17) * (height[j] - goalHeight + 17);
			}
		} 
		costs[i] = cost;
	}
	
	sort(costs, costs+101);

	
	cout << costs[0] << endl;
} 
