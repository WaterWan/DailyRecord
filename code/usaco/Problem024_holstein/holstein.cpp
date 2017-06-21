/**
ID: njuwz151
TASK: holstein
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>

using namespace std;

const int max_v = 30;
const int max_g = 20;

int main() {
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	
	bitset<max_g> minbit(0);
	int min_count = max_g + 1;
	int feed[max_v];
	
	int v;
	int req[max_v];
	cin >> v;
	for(int i = 0; i < v; i++) {
		cin >> req[i];
	}
	int g;
	int food[max_g][max_v];
	cin >> g;
	for(int i = 0; i < g; i++) {
		for(int j = 0; j < v; j++) {
			cin >> food[i][j];
		}
	}
	
	for(int i = 0; i < (1 << g); i++) {
		bitset<max_g> bit(i);
		int to_feed[max_v];
		memset(to_feed, 0, sizeof to_feed);
		for(int j = 0; j < g; j++) {
			if(bit[j]) {
				 for(int k = 0; k < v; k++) {
				 	to_feed[k] += food[j][k];
				 }
			}
		}
		
		bool valid = true;
		for(int j = 0; j < v; j++) {
			if(to_feed[j] < req[j]) {
				valid = false;
				break;
			}
		}
		if(valid && int(bit.count()) < min_count) {
			minbit = bit;
			min_count = minbit.count();
			continue;
		}
		
		if(valid && int(bit.count()) == min_count) {
			bool ok = true;
			for(int i = 0; i < g; i++) {
				if(bit[i] > minbit[i]) {
					break;
				} else if(bit[i] < minbit[i]) {
					ok = false;
					break;
				}
			}
			if(ok) {
				minbit = bit;
				min_count = minbit.count();	
			}
		}
 	}
 	
 	cout << min_count;
 	for(int i = 0; i < g; i++) {
 		if(minbit[i]) {
 			cout << " " << i+1;
		 }
	}
	cout << endl;
}
