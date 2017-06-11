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

bool cycle_exists();

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
				if(next_on_right[i] == 0 || X[j] < X[next_on_right[i]]) {
					next_on_right[i] = j;
				}
			}
		}
	}
	
	cout << solve() << endl;	
}

int solve() {
	
	// ��ֹ���������г涴����� 
	int i;
	int total = 0;
	for(i = 1; i <= N; i++) {
		if(partner[i] == 0) {
			break;
		}
	}
	if(i > N) {
		if(cycle_exists()) {
			return 1;
		} else {
			return 0;
		}
	}
	
	// ״̬ת�� 
	for(int j = i + 1; j <= N; j++) {
		if(partner[j] == 0) {
			partner[i] = j;
			partner[j] = i;
			// ��һ�о�����״̬ת�� 
			total += solve();
			// ���״̬���´��������Ͳ����������� 
			partner[i] = partner[j] = 0;
 		}
	}
	return total;
		 
}

bool cycle_exists() {
	for(int start = 1; start <= N; start++) {
		int pos = start;
		for(int count = 0; count < N; count++) {
			pos = next_on_right[partner[pos]];
		}
		if(pos != 0) {
			return true;
		}
	}
	return false;
}
