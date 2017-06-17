/**
ID: njuwz151
TASK: sprime
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int N;
int nums[2][4] = {{2, 3, 5, 7}, {1, 3, 7, 9}};


bool is_prime(int a);
void dfs(int n, int a);

int main() {
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	cin >> N;
	dfs(0, 0);
}

void dfs(int n, int a) {
	if(n == N) {
		cout << a << endl;
		return;
	}
	for(int i = 0; i < 4; i++) {
		int temp = a * 10 + nums[!!n][i];
		if(is_prime(temp)) {
			dfs(n+1, temp);
		} 
	}
}

bool is_prime(int a) {
	if(a < 2) {
		return false;
	}
	if(a == 2) {
		return true;
	}
	int max = sqrt(a) + 1;
	for(int i = 2; i < max; i++) {
		if(a % i == 0) {
			return false;
		}
	}
	return true;
}
