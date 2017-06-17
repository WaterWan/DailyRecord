/**
ID: njuwz151
TASK: pprime
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;


bool is_prime(int a);

int main() {
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for(int i = 5; i <= 11; i++) {
		if(a<=i && i<=b && is_prime(i)) {
			cout << i << endl;
		} else if(b < i) {
			break;
		}
	} 
	int num;
	for(int i1 = 0; i1 <= 9; i1++) {
		for(int i2 = 0; i2 <= 9; i2++) {
			for(int i3 = 0; i3 <= 9; i3++) {
				for(int i4 = 0; i4 <= 9; i4++) {
					for(int i5 = 0; i5 <= 9; i5++) {
						if(!i1 && !i2 && !i3) {
							num = i4 * 101 + i5 * 10;
						} else if(!i1 && !i2) {
							num = i3 * 10001 + i4 * 1010 + i5 * 100;
						} else if(!i1) {
							num = i2 * 1000001 + i3 * 100010 + i4 * 10100 + i5 * 1000;
						} else {
							num = i1 * 100000001 + i2 * 10000010 + i3 * 1000100 + i4 * 101000 + i5 * 10000;
						}
						if(is_prime(num) && a <= num && num <= b) {
							cout << num << endl;
						} else if(b < num) {
							return 0;
						}
					}
				}
			}
		}
	}
	return 0;
}

bool is_prime(int a) {
	int max = sqrt(a) + 1;
	for(int i = 2; i <= sqrt(a); i++) {
		if(a % i == 0) {
			return false;
		}
	}
	return true;
}
