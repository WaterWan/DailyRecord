/**
ID: njuwz151
TASK: combo
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool isValid(int src, int dest, int n);

int main() {
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
	
	int n;
	cin >> n;
	int a[3];
	for(int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	int b[3];
	for(int i = 0; i < 3; i++) {
		cin >> b[i];
	}
	
	int count = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				bool flag = false;
				if(isValid(i, a[0], n) && isValid(j, a[1], n) && isValid(k, a[2], n)) {
					flag = true;
				}
				if(isValid(i, b[0], n) && isValid(j, b[1], n) && isValid(k, b[2], n)) {
					flag = true;
				}
				if(flag) {
					count++;
				}
			}
		}
	}
	cout << count << endl;
	
} 

bool isValid(int src, int dest, int n) {
	for(int i = -2; i <= 2; i++) {
		if(((src + i + n) % n) == (dest %n)) {
			return true;
		}
	}
	return false;
}
