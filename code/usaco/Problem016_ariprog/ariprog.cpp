/**
ID: njuwz151
TASK: ariprog
LANG: C++
*/
#include <bits/stdc++.h>

#define MAXN 250

using namespace std;

bool exists[2 * MAXN * MAXN + 1];
int number[2 * MAXN * MAXN + 1]; 

int main() {
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	int N;
	int M;
	cin >> N >> M;
	memset(exists, 0, sizeof exists);
	for(int i = 0; i <= M; i++) {
		for(int j = 0; j <=M; j++) {
			exists[i * i + j * j] = 1;
		}
	} 
	bool solution = false;
	int count = 0;
	for(int i = 0; i < MAXN * MAXN + 1; i++) {
		if(exists[i]) {
			number[count] = i;
			count++;
		}
	}

	for(int j = 1; j <= (MAXN * MAXN + 1) / 4; j++) {
		for(int i = 0; i < count; i++) {
			for(int k = 0; k < N; k++) {
				if(number[i] + j * k > 2 * MAXN * MAXN + 1) {
					break;
				}
				if(!exists[number[i] + j * k]) {
					break;
				}
				if(k == N - 1) {
					cout << number[i] << " " << j << endl;
					solution = true;
				}
			}
		}
	}

	if(!solution) {
		cout << "NONE" << endl;
	}

}
