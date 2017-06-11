/**
ID: njuwz151
TASK: wormhole
LANG: C++
*/
#include <iostream>
#include <cstdio>

#define MAXN 12

using namespace std;

int N;
int X[MAXN + 1];
int Y[MAXN + 1];
int next_on_right[MAXN + 1];
int partner[MAXN + 1];

int solve();

bool exist_cycle();

int main() {
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);
	
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j) {
				continue;
			}
			if(X[i] < X[j] && Y[i] == Y[j]) {
				if (next_on_right[i] == 0 ||  
                    X[j]-X[i] < X[next_on_right[i]]-X[i]) {
                    	next_on_right[i] = j; 
					}
			}
		}
	}

	cout << solve() << endl;
	
}

int solve() {
	int i;
	int total = 0;
	for(i = 1; i <= N; i++) {
		if(partner[i] == 0) {
			break;
		}
	}
	if(i > N) {
		if(exist_cycle()) {
			return 1;
		} else {
			return 0;
		}
	}
	for(int j = i + 1; j <= N; j++) {
		if(partner[j] == 0) {
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = 0;
			partner[j] = 0;
		}
	}
	return total;
}

bool exist_cycle() {
	for (int start = 1; start <= N; start++) {
		int pos = start;
		for(int step = 0; step < N; step++) {
			pos = next_on_right[partner[pos]];
		}
		if(pos != 0) {
			return true;
		}
	}
	return false;
}

