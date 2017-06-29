/**
ID: njuwz151
TASK: hamming
LANG: C++
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 9;

int count(int a, int b);

int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	
	int n, b, d;
	cin >> n >> b >> d;
	
	int result[1 << maxn];
	result[0] = 0;
	int n_ptr = 1;
	for(int i = 1; i < (1 << b); i++) {
		if(n_ptr > n) {
			break;
		}
		bool can_add = true;
		for(int j = 0; j < n_ptr; j++) {
			if(count(i, result[j]) < d) {
				can_add = false;
				break;
			}
		}
		if(can_add) {
			result[n_ptr] = i;
			n_ptr++; 
		}
	}
	for(int i = 0; i < n - 1; i++) {
		cout << result[i];
		if((i + 1) % 10) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
	cout << result[n - 1] << endl;
} 

int count(int a, int b) {
	int result = 0;
	for(int i = 0; i < maxn; i++) {
		if(((a>>i) & 1) != ((b>>i) & 1)) {
			result++;
		}
	}
	return result;
}
