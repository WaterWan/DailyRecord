#include <algorithm>
#include <vector>
#include <climits>
#include <stdio.h>

using namespace std;

const int maxn = 200005;
int l, r, cost, d;
vector<pair<int, int> > S[maxn];

int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	int total_cost = INT_MAX;
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &l, &r, &cost);
		d = r - l + 1;
		S[d].push_back({l, cost});
	}
	for(int i = 0; i <= x; i++) {
		sort(S[i].begin(), S[i].end());
	} 
	for(int i = 1; i < x; i++) {
		auto &u = S[i];
		auto &v = S[x-i];
		int min = INT_MAX;
		for(int j = 0, k = 0; j < v.size(); j++) {
			while(k < u.size() && u[k].first + i - 1 < v[j].first) {
				if(u[k].second < min) {
					min = u[k].second;
				}
				k++;
			}
			if(min != INT_MAX) {
				int temp = min + v[j].second;
				if(temp < total_cost) {
					total_cost = temp;
				}
			}
		}
	}
	if(total_cost == INT_MAX) {
		total_cost = -1;
	}
	printf("%d\n", total_cost);

}


