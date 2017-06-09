/**
ID: njuwz151
TASK: crypt1
LANG: C++
*/
#include <iostream>
#include <cstdio>

#define MAXN 10

using namespace std;

bool inArray(int src, int array[], int n);

int main() {
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	
	int n;
	cin >> n;
	int d[MAXN];
	int a[3];
	int b[2];
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	int count = 0;
	for(int i = 0; i < n; i++) {
		a[0] = d[i];
		for(int j =  0; j < n; j++) {
			a[1] = d[j];
			for(int k = 0; k < n; k++) {
				a[2] = d[k];
				for(int i1 = 0; i1 < n; i1++) {
					b[0] = d[i1];
					for(int j1 = 0; j1 < n; j1++) {
						b[1] = d[j1];
						int src1 = a[0] * 100 + a[1] * 10 + a[2];
						int src2 = b[0] * 10 + b[1];
						if(src1*b[0] > 999 || src1*b[1] > 999) {
							continue;
						}
						if(inArray(src1*src2, d, n) && inArray(b[0]*src1, d, n) && inArray(b[1]*src1, d, n)) {
							count++;
//							cout << src1 << "  " << src2 << endl;
						}
					}
				}
			}
		}
	}
	cout << count << endl;
}

bool inArray(int src, int array[], int n) {
	bool flag = false;
	while(src > 0) {
		for(int i = 0; i < n; i++) {
			if(src % 10 == array[i]) {
				flag = true;
			}
		}
		if(!flag) {
			return false;
		} else {
			flag = false;
			src /= 10;
		}
	}
	return true;
}
